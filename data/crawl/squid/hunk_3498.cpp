     ret = FD_WRITE_METHOD(ll->wfd, b->buf + b->written_len, b->len - b->written_len);
     debugs(50, 3, "logfileHandleWrite: " << lf->path << ": write returned " << ret);
     if (ret < 0) {
-	if (ignoreErrno(errno)) {
-	    /* something temporary */
-	    goto reschedule;
-	}
-	debugs(50, DBG_IMPORTANT,"logfileHandleWrite: " << lf->path << ": error writing (" << xstrerror() << ")");
-	/* XXX should handle this better */
-	fatal("I don't handle this error well!");
+        if (ignoreErrno(errno)) {
+            /* something temporary */
+            goto reschedule;
+        }
+        debugs(50, DBG_IMPORTANT,"logfileHandleWrite: " << lf->path << ": error writing (" << xstrerror() << ")");
+        /* XXX should handle this better */
+        fatal("I don't handle this error well!");
     }
     if (ret == 0) {
-	/* error? */
-	debugs(50, DBG_IMPORTANT, "logfileHandleWrite: " << lf->path << ": wrote 0 bytes?");
-	/* XXX should handle this better */
-	fatal("I don't handle this error well!");
+        /* error? */
+        debugs(50, DBG_IMPORTANT, "logfileHandleWrite: " << lf->path << ": wrote 0 bytes?");
+        /* XXX should handle this better */
+        fatal("I don't handle this error well!");
     }
     /* ret > 0, so something was written */
     b->written_len += ret;
     assert(b->written_len <= b->len);
     if (b->written_len == b->len) {
-	/* written the whole buffer! */
-	logfileFreeBuffer(lf, b);
-	b = NULL;
+        /* written the whole buffer! */
+        logfileFreeBuffer(lf, b);
+        b = NULL;
     }
     /* Is there more to write? */
     if (ll->bufs.head == NULL) {
-	goto finish;
+        goto finish;
     }
     /* there is, so schedule more */
 
-  reschedule:
+reschedule:
     commSetSelect(ll->wfd, COMM_SELECT_WRITE, logfileHandleWrite, lf, 0);
     ll->flush_pending = 1;
-  finish:
+finish:
     return;
 }
 
