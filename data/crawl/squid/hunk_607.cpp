     HttpReply *const reply = Ftp::HttpReplyWrapper(ctrl.replycode, ctrl.last_reply, httpStatus, clen);
     if (ctrl.message) {
         for (wordlist *W = ctrl.message; W && W->next; W = W->next)
-            reply->header.putStr(HDR_FTP_PRE, httpHeaderQuoteString(W->key).c_str());
-        // no hdrCacheInit() is needed for after HDR_FTP_PRE addition
+            reply->header.putStr(Http::HdrType::FTP_PRE, httpHeaderQuoteString(W->key).c_str());
+        // no hdrCacheInit() is needed for after Http::HdrType::FTP_PRE addition
     }
     return reply;
 }