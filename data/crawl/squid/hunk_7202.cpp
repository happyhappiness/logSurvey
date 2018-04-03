     storeAppendPrintf(e, "Server: Squid %s\r\n", version_string);
     if (ftpState->size > 0) {
 	storeAppendPrintf(e, "Content-Length: %d\r\n", ftpState->size);
-        reply->content_length = ftpState->size;
+	reply->content_length = ftpState->size;
     }
     if (mime_type) {
 	storeAppendPrintf(e, "Content-Type: %s\r\n", mime_type);
-    	xstrncpy(reply->content_type, mime_type, HTTP_REPLY_FIELD_SZ);
+	xstrncpy(reply->content_type, mime_type, HTTP_REPLY_FIELD_SZ);
     }
     if (mime_enc)
 	storeAppendPrintf(e, "Content-Encoding: %s\r\n", mime_enc);
