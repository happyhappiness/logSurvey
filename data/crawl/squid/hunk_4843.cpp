     }
 
     HTTPMSGLOCK(urlres_r);
-    httpHeaderPutStr(&urlres_r->header, HDR_ACCEPT, "text/plain");
+    urlres_r->header.putStr(HDR_ACCEPT, "text/plain");
 }
 
 void
