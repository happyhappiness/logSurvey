     if (!TheICAPConfig.reuse_connections)
         buf.Printf("Connection: close\r\n");
 
+    // we must forward "Proxy-Authenticate" and "Proxy-Authorization"
+    // as ICAP headers.
+    if (virgin.header->header.has(HDR_PROXY_AUTHENTICATE)) 
+        buf.Printf("Proxy-Authenticate: %s\r\n", 
+                virgin.header->header.getByName("Proxy-Authenticate").buf());    
+    
+    if (virgin.header->header.has(HDR_PROXY_AUTHORIZATION)) 
+        buf.Printf("Proxy-Authorization: %s\r\n", 
+                virgin.header->header.getByName("Proxy-Authorization").buf());
+
     buf.Printf("Encapsulated: ");
 
     MemBuf httpBuf;
