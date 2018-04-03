         return;
     }
 
-    urlres_r->header.putStr(HDR_ACCEPT, "text/plain");
+    urlres_r->header.putStr(Http::HdrType::ACCEPT, "text/plain");
 }
 
 void
