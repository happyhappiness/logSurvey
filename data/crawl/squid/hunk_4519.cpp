     if (mime_enc)
         reply->header.putStr(HDR_CONTENT_ENCODING, mime_enc);
 
-    setReply();
+    setVirginReply(reply);
+    adaptOrFinalizeReply();
 }
 
 void
