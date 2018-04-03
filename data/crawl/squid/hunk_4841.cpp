     /* add custom headers */
     assert(!req->header.len);
 
-    httpHeaderPutStr(&req->header, HDR_ACCEPT, StoreDigestMimeStr);
+    req->header.putStr(HDR_ACCEPT, StoreDigestMimeStr);
 
-    httpHeaderPutStr(&req->header, HDR_ACCEPT, "text/html");
+    req->header.putStr(HDR_ACCEPT, "text/html");
 
     if (p->login)
         xstrncpy(req->login, p->login, MAX_LOGIN_SZ);
