      * XXX These should use HttpHdr interfaces instead of Printfs
      */
     const Adaptation::ServiceConfig &s = service().cfg();
-    buf.Printf("%s %s ICAP/1.0\r\n", s.methodStr(), s.uri.buf());
-    buf.Printf("Host: %s:%d\r\n", s.host.buf(), s.port);
+    buf.Printf("%s %.*s ICAP/1.0\r\n", s.methodStr(), s.uri.size(), s.uri.rawBuf());
+    buf.Printf("Host: %.*s:%d\r\n", s.host.size(), s.host.rawBuf(), s.port);
     buf.Printf("Date: %s\r\n", mkrfc1123(squid_curtime));
 
     if (!TheICAPConfig.reuse_connections)
         buf.Printf("Connection: close\r\n");
 
     // we must forward "Proxy-Authenticate" and "Proxy-Authorization"
     // as ICAP headers.
-    if (virgin.header->header.has(HDR_PROXY_AUTHENTICATE))
-        buf.Printf("Proxy-Authenticate: %s\r\n",
-                   virgin.header->header.getByName("Proxy-Authenticate").buf());
+    if (virgin.header->header.has(HDR_PROXY_AUTHENTICATE)) {
+        String vh=virgin.header->header.getByName("Proxy-Authenticate");
+        buf.Printf("Proxy-Authenticate: %.*s\r\n",
+                   vh.size(), vh.rawBuf());
+    }
 
-    if (virgin.header->header.has(HDR_PROXY_AUTHORIZATION))
-        buf.Printf("Proxy-Authorization: %s\r\n",
-                   virgin.header->header.getByName("Proxy-Authorization").buf());
+    if (virgin.header->header.has(HDR_PROXY_AUTHORIZATION)) {
+        String vh=virgin.header->header.getByName("Proxy-Authorization");
+        buf.Printf("Proxy-Authorization: %.*s\r\n",
+                   vh.size(), vh.rawBuf());
+    }
 
     buf.Printf("Encapsulated: ");
 
