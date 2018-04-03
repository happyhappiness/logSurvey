 
     /* maybe append Connection: keep-alive */
     if (flags.keepalive) {
-        if (flags.proxying) {
-            hdr_out->putStr(HDR_PROXY_CONNECTION, "keep-alive");
-        } else {
-            hdr_out->putStr(HDR_CONNECTION, "keep-alive");
-        }
+        hdr_out->putStr(HDR_CONNECTION, "keep-alive");
     }
 
     /* append Front-End-Https */
