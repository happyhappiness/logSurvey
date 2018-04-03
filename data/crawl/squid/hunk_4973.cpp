         p = "[none]";
     }
 
-    memBufPrintf(&str, "\r\n");
+    str.Printf("\r\n");
     /* - FTP stuff */
 
     if (err->ftp.request) {
-        memBufPrintf(&str, "FTP Request: %s\r\n", err->ftp.request);
-        memBufPrintf(&str, "FTP Reply: %s\r\n", err->ftp.reply);
-        memBufPrintf(&str, "FTP Msg: ");
+        str.Printf("FTP Request: %s\r\n", err->ftp.request);
+        str.Printf("FTP Reply: %s\r\n", err->ftp.reply);
+        str.Printf("FTP Msg: ");
         wordlistCat(err->ftp.server_msg, &str);
-        memBufPrintf(&str, "\r\n");
+        str.Printf("\r\n");
     }
 
-    memBufPrintf(&str, "\r\n");
-    memBufPrintf(mb, "&body=%s", rfc1738_escape_part(str.buf));
-    memBufClean(&str);
+    str.Printf("\r\n");
+    mb->Printf("&body=%s", rfc1738_escape_part(str.buf));
+    str.clean();
     return 0;
 }
 
