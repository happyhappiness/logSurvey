     /* - IP stuff */
     str.Printf("ClientIP: %s\r\n", inet_ntoa(err->src_addr));
 
-    if (err->host) {
-        str.Printf("ServerIP: %s\r\n", err->host);
+    if (r && r->hier.host) {
+        str.Printf("ServerIP: %s\r\n", r->hier.host);
     }
 
     str.Printf("\r\n");
