 bool
 ConnStateData::parseProxy2p0()
 {
-    if ((in.buf[0] & 0xF0) != 0x20) // version == 2 is mandatory
+    static const SBuf::size_type prefixLen = Proxy2p0magic.length();
+    if (in.buf.length() < prefixLen + 4)
+        return false; // need more bytes
+
+    if ((in.buf[prefixLen] & 0xF0) != 0x20) // version == 2 is mandatory
         return proxyProtocolError("PROXY/2.0 error: invalid version");
 
-    const char command = (in.buf[0] & 0x0F);
+    const char command = (in.buf[prefixLen] & 0x0F);
     if ((command & 0xFE) != 0x00) // values other than 0x0-0x1 are invalid
         return proxyProtocolError("PROXY/2.0 error: invalid command");
 
-    const char family = (in.buf[1] & 0xF0) >>4;
+    const char family = (in.buf[prefixLen+1] & 0xF0) >>4;
     if (family > 0x3) // values other than 0x0-0x3 are invalid
         return proxyProtocolError("PROXY/2.0 error: invalid family");
 
-    const char proto = (in.buf[1] & 0x0F);
+    const char proto = (in.buf[prefixLen+1] & 0x0F);
     if (proto > 0x2) // values other than 0x0-0x2 are invalid
         return proxyProtocolError("PROXY/2.0 error: invalid protocol type");
 
-    const char *clen = in.buf.rawContent() + Proxy2p0magic.length() + 2;
+    const char *clen = in.buf.rawContent() + prefixLen + 2;
     const uint16_t len = ntohs(*(reinterpret_cast<const uint16_t *>(clen)));
 
-    if (in.buf.length() < Proxy2p0magic.length() + 4 + len)
+    if (in.buf.length() < prefixLen + 4 + len)
         return false; // need more bytes
 
-    in.buf.consume(Proxy2p0magic.length() + 4); // 4 being the extra bytes
+    in.buf.consume(prefixLen + 4); // 4 being the extra bytes
     const SBuf extra = in.buf.consume(len);
     needProxyProtocolHeader_ = false; // found successfully
 
     // LOCAL connections do nothing with the extras
     if (command == 0x00/* LOCAL*/)
         return true;
 
-    typedef union proxy_addr {
+    union pax {
         struct {        /* for TCP/UDP over IPv4, len = 12 */
             struct in_addr src_addr;
             struct in_addr dst_addr;
