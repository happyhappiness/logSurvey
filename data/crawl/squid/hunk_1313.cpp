 
     if (ctrl.message) {
         for (wordlist *W = ctrl.message; W && W->next; W = W->next)
-            header.putStr(HDR_FTP_PRE, httpHeaderQuoteString(W->key).termedBuf());
+            header.putStr(HDR_FTP_PRE, httpHeaderQuoteString(W->key).c_str());
     }
     if (ctrl.replycode > 0)
         header.putInt(HDR_FTP_STATUS, ctrl.replycode);
