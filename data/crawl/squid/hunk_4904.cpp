 
 void ICAPModXact::makeRequestHeaders(MemBuf &buf)
 {
+    /*
+     * XXX These should use HttpHdr interfaces instead of Printfs
+     */
     const ICAPServiceRep &s = service();
     buf.Printf("%s %s ICAP/1.0\r\n", s.methodStr(), s.uri.buf());
     buf.Printf("Host: %s:%d\r\n", s.host.buf(), s.port);
+    buf.Printf("Date: %s\r\n", mkrfc1123(squid_curtime));
+
+    if (!TheICAPConfig.reuse_connections)
+        buf.Printf("Connection: close\r\n");
+
     buf.Printf("Encapsulated: ");
 
     MemBuf httpBuf;
+
     httpBuf.init();
 
     // build HTTP request header, if any
