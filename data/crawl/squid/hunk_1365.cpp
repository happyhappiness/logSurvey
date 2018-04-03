             return true;
         }
 
-    } else if (in.buf.length() >= proxy1magic.length()) {
+        // detect and parse PROXY protocol version 2 header
+    } else if (in.buf.length() > proxy2magic.length() && in.buf.startsWith(proxy2magic)) {
+
+        if ((in.buf[0] & 0xF0) != 0x20) // version == 2 is mandatory
+            proxyProtocolError(true);
+
+        const char command = (in.buf[0] & 0x0F);
+        if ((command & 0xFE) != 0x00) // values other than 0x0-0x1 are invalid
+            proxyProtocolError(true);
+
+        const char family = (in.buf[1] & 0xF0) >>4;
+        if (family > 0x2) // values other than 0x0-0x3 are invalid. we dont accept 0x3
+            proxyProtocolError(true);
+
+        const char proto = (in.buf[1] & 0x0F);
+        if (proto > 0x2) // values other than 0x0-0x2 are invalid
+            proxyProtocolError(true);
+
+        const char *clen = in.buf.rawContent() + proxy2magic.length() + 2;
+        const uint16_t len = ntohs(*(reinterpret_cast<const uint16_t *>(clen)));
+
+        if (in.buf.length() < proxy2magic.length() + 4 + len)
+            return false; // need more bytes
+
+        in.buf.consume(proxy2magic.length() + 4); // 4 being the extra bytes
+        const SBuf extra = in.buf.consume(len);
+        needProxyProtocolHeader_ = false; // found successfully
+
+        // LOCAL connections do nothing with the extras
+        if (command == 0x00/* LOCAL*/)
+            return true;
+
+        typedef union proxy_addr {
+            struct {        /* for TCP/UDP over IPv4, len = 12 */
+                struct in_addr src_addr;
+                struct in_addr dst_addr;
+                uint16_t src_port;
+                uint16_t dst_port;
+            } ipv4_addr;
+            struct {        /* for TCP/UDP over IPv6, len = 36 */
+                 struct in6_addr src_addr;
+                 struct in6_addr dst_addr;
+                 uint16_t src_port;
+                 uint16_t dst_port;
+            } ipv6_addr;
+#if NOT_SUPPORTED
+            struct {        /* for AF_UNIX sockets, len = 216 */
+                 uint8_t src_addr[108];
+                 uint8_t dst_addr[108];
+            } unix_addr;
+#endif
+        } pax;
+
+        const pax *ipu = reinterpret_cast<const pax*>(extra.rawContent());
+
+        // replace the client connection values
+        debugs(33, 5, "PROXY protocol on connection " << clientConnection);
+        switch (family)
+        {
+        case 0x1: // IPv4
+            clientConnection->local = ipu->ipv4_addr.dst_addr;
+            clientConnection->local.port(ntohs(ipu->ipv4_addr.dst_port));
+            clientConnection->remote = ipu->ipv4_addr.src_addr;
+            clientConnection->remote.port(ntohs(ipu->ipv4_addr.src_port));
+            break;
+        case 0x2: // IPv6
+            clientConnection->local = ipu->ipv6_addr.dst_addr;
+            clientConnection->local.port(ntohs(ipu->ipv6_addr.dst_port));
+            clientConnection->remote = ipu->ipv6_addr.src_addr;
+            clientConnection->remote.port(ntohs(ipu->ipv6_addr.src_port));
+            break;
+        default: // do nothing
+            break;
+        }
+        debugs(33, 5, "PROXY upgrade: " << clientConnection);
+
+        // repeat fetch ensuring the new client FQDN can be logged
+        if (Config.onoff.log_fqdn)
+            fqdncache_gethostbyaddr(clientConnection->remote, FQDN_LOOKUP_IF_MISS);
+
+        return true;
+
+        // detect and terminate other protocols
+    } else if (in.buf.length() >= proxy2magic.length()) {
+
         // input other than the PROXY header is a protocol error
         return proxyProtocolError(true);
     }