 }
 #endif
 
+void
+ServerStateData::sendBodyIsTooLargeError()
+{
+    ErrorState *err = errorCon(ERR_TOO_BIG, HTTP_FORBIDDEN, request);
+    err->xerrno = errno;
+    fwd->fail(err);
+    fwd->dontRetry(true);
+    abortTransaction("Virgin body too large.");
+}
+
 // TODO: when HttpStateData sends all errors to ICAP, 
 // we should be able to move this at the end of setVirginReply().
 void
