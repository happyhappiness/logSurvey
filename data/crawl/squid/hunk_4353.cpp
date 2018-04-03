         return;
     }
 
-    if (!reply) {
-	reply = HTTPMSGLOCK(entry->mem_obj->getReply()->clone());
-    }
-    if ((long)reqofs < reply->hdr_sz) {
-        waitForMoreData();
-        return;
-    }
-    if (reply) {
+    cloneReply();
 
-        /* handle headers */
+    /* handle headers */
 
-        if (Config.onoff.log_mime_hdrs) {
-            size_t k;
-
-            if ((k = headersEnd(buf, reqofs))) {
-                safe_free(http->al.headers.reply);
-                http->al.headers.reply = (char *)xcalloc(k + 1, 1);
-                xstrncpy(http->al.headers.reply, buf, k);
-            }
-        }
-
-        holdingBuffer = result;
-        processReplyAccess();
-        return;
+    if (Config.onoff.log_mime_hdrs) {
+	size_t k;
 
-    } else {
-        debugs(88, 0, "clientReplyContext::sendMoreData: Unable to parse reply headers within a single HTTP_REQBUF_SZ length buffer");
-        StoreIOBuffer tempBuffer;
-        tempBuffer.flags.error = 1;
-        /* XXX FIXME: make an html error page here */
-        sendStreamError(tempBuffer);
-        return;
+	if ((k = headersEnd(buf, reqofs))) {
+	    safe_free(http->al.headers.reply);
+	    http->al.headers.reply = (char *)xcalloc(k + 1, 1);
+	    xstrncpy(http->al.headers.reply, buf, k);
+	}
     }
-    fatal ("clientReplyContext::sendMoreData: Unreachable code reached \n");
+
+    holdingBuffer = result;
+    processReplyAccess();
+    return;
 }
 
 
