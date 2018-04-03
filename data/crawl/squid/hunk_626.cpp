     HttpRequest *const request = http->request;
     assert(request != NULL);
     HttpHeader &header = request->header;
-    header.delById(HDR_FTP_COMMAND);
-    header.putStr(HDR_FTP_COMMAND, "PASV");
-    header.delById(HDR_FTP_ARGUMENTS);
-    header.putStr(HDR_FTP_ARGUMENTS, "");
+    header.delById(Http::HdrType::FTP_COMMAND);
+    header.putStr(Http::HdrType::FTP_COMMAND, "PASV");
+    header.delById(Http::HdrType::FTP_ARGUMENTS);
+    header.putStr(Http::HdrType::FTP_ARGUMENTS, "");
     debugs(9, 5, "client data command converted to fake PASV");
 }
 
