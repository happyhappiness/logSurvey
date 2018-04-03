     fwdStart(-1, e, req);
     cbdataLock(fetch);
     cbdataLock(fetch->pd);
-    storeClientCopy(fetch->sc, e, 0, 0, 4096, memAllocate(MEM_4K_BUF),
-	peerDigestFetchReply, fetch);
+    storeClientCopy(fetch->sc, e, 0, SM_PAGE_SIZE, fetch->buf,
+	peerDigestHandleReply, fetch);
 }
 
-/* wait for full http headers to be received then parse them */
+
+/* Handle the data copying .. */
+
+/*
+ * This routine handles the copy data and then redirects the
+ * copy to a bunch of subfunctions depending upon the copy state.
+ * It also tracks the buffer offset and "seen", since I'm actually
+ * not interested in rewriting everything to suit my little idea.
+ */
 static void
+peerDigestHandleReply(void *data, char *buf, ssize_t copysize)
+{
+    DigestFetchState *fetch = data;
+    PeerDigest *pd = fetch->pd;
+    int retsize = -1;
+    digest_read_state_t prevstate;
+    int newsize;
+
+    assert(pd && buf);
+
+    /* Update the buffer size */
+    fetch->bufofs += copysize;
+
+    assert(fetch->bufofs <= SM_PAGE_SIZE);
+
+    /* If we've fetched enough, return */
+    if (peerDigestFetchedEnough(fetch, fetch->buf, fetch->bufofs, "peerDigestHandleReply"))
+	return;
+
+    /* Call the right function based on the state */
+    /* (Those functions will update the state if needed) */
+    cbdataLock(fetch);
+
+    /* Repeat this loop until we're out of data OR the state changes */
+    /* (So keep going if the state has changed and we still have data */
+    do {
+        prevstate = fetch->state;
+        switch(fetch->state) {
+            case DIGEST_READ_REPLY:
+                retsize = peerDigestFetchReply(data, fetch->buf, fetch->bufofs);
+              break;
+            case DIGEST_READ_HEADERS:
+                retsize = peerDigestSwapInHeaders(data, fetch->buf, fetch->bufofs);
+              break;
+            case DIGEST_READ_CBLOCK:
+                retsize = peerDigestSwapInCBlock(data, fetch->buf, fetch->bufofs);
+              break;
+            case DIGEST_READ_MASK:
+                retsize = peerDigestSwapInMask(data, fetch->buf, fetch->bufofs);
+              break;
+            case DIGEST_READ_NONE:
+              break;
+            case DIGEST_READ_DONE:
+                goto finish;
+              break;
+            default:
+                fatal("Bad digest transfer mode!\n");
+        }
+
+        if (retsize < 0)
+            goto finish;
+        /*
+         * The returned size indicates how much of the buffer was read -
+         * so move the remainder of the buffer to the beginning
+         * and update the bufofs / bufsize
+         */
+        newsize = fetch->bufofs - retsize;
+        xmemmove(fetch->buf, fetch->buf + retsize, fetch->bufofs - newsize);
+        fetch->bufofs = newsize;
+
+    } while (prevstate != fetch->state && fetch->bufofs > 0);
+
+    /* Update the copy offset */
+    fetch->offset += copysize;
+
+    /* Schedule another copy */
+    if (cbdataValid(fetch)) {
+        storeClientCopy(fetch->sc, fetch->entry, fetch->offset, SM_PAGE_SIZE - fetch->bufofs,
+          fetch->buf + fetch->bufofs, peerDigestHandleReply, fetch);
+    }
+finish:
+    /* Unlock our data - we've finished with it for now */
+    cbdataUnlock(fetch);
+}
+
+
+
+/* wait for full http headers to be received then parse them */
+/*
+ * This routine handles parsing the reply line.
+ * If the reply line indicates an OK, the same data is thrown
+ * to SwapInHeaders(). If the reply line is a NOT_MODIFIED,
+ * we simply stop parsing.
+ */
+static int
 peerDigestFetchReply(void *data, char *buf, ssize_t size)
 {
     DigestFetchState *fetch = data;
