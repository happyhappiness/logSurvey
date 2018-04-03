         reply->header.putStr(Http::HdrType::CONTENT_ENCODING, mime_enc);
 
     entry->replaceHttpReply(reply);
+    gopherState->reply_ = reply;
 }
 
 /**
