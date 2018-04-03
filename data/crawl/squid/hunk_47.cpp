     if (mime_enc)
         reply->header.putStr(Http::HdrType::CONTENT_ENCODING, mime_enc);
 
-    reply->sources |= HttpMsg::srcFtp;
+    reply->sources |= Http::Message::srcFtp;
     setVirginReply(reply);
     adaptOrFinalizeReply();
 }
