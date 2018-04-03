     return false;
 }
 
+/**
+ * Perform follow_x_forwarded_for ACL tests on the
+ * client which connected to PROXY protocol port.
+ */
+void
+ConnStateData::proxyProtocolValidateClient()
+{
+    ACLFilledChecklist ch(Config.accessList.followXFF, NULL, clientConnection->rfc931);
+    ch.src_addr = clientConnection->remote;
+    ch.my_addr = clientConnection->local;
+    // TODO: we should also pass the port details for myportname here.
+
+    if (ch.fastCheck() != ACCESS_ALLOWED) {
+        // terminate the connection. invalid input.
+        stopReceiving("PROXY client not permitted by ACLs");
+        stopSending("PROXY client not permitted by ACLs");
+    }
+}
+
+/**
+ * Perform cleanup on PROXY protocol errors.
+ * If header parsing hits a fatal error terminate the connection,
+ * otherwise wait for more data.
+ */
+bool
+ConnStateData::proxyProtocolError(bool fatalError)
+{
+    if (fatalError) {
+        // terminate the connection. invalid input.
+        stopReceiving("PROXY protocol error");
+        stopSending("PROXY protocol error");
+    }
+    return false;
+}
+
+/**
+ * Parse the connection read buffer for PROXY protocol header.
+ * Only version 1 header currently supported.
+ */
+bool
+ConnStateData::parseProxyProtocolMagic()
+{
+    // magic octet prefix for PROXY protocol version 1
+    // http://www.haproxy.org/download/1.5/doc/proxy-protocol.txt
+    static const SBuf proxy1magic("PROXY ");
+
+    // detect and parse PROXY protocol version 1 header
+    if (in.buf.startsWith(proxy1magic)) {
+        ::Parser::Tokenizer tok(in.buf);
+        tok.skip(proxy1magic);
+
+        SBuf tcpVersion;
+        if (!tok.prefix(tcpVersion, CharacterSet::ALPHA+CharacterSet::DIGIT))
+            return proxyProtocolError(tok.atEnd());
+
+        if (!tcpVersion.cmp("UNKNOWN")) {
+            // skip to first LF (assumes it is part of CRLF)
+            const SBuf::size_type pos = in.buf.findFirstOf(CharacterSet::LF);
+            if (pos != SBuf::npos) {
+                if (in.buf[pos-1] != '\r')
+                    return proxyProtocolError(false); // invalid terminator
+                // found valid but unusable header
+                in.buf.consume(pos);
+                needProxyProtocolHeader_ = false;
+                return true;
+            }
+            // else, no LF found
+
+            // protocol error only if there are more than 107 bytes prefix header
+            return proxyProtocolError(in.buf.length() > 107);
+
+        } else if (!tcpVersion.cmp("TCP",3)) {
+
+            // skip SP after protocol version
+            if (!tok.skip(' '))
+                return proxyProtocolError(tok.atEnd());
+
+            SBuf ipa, ipb;
+            int64_t porta, portb;
+            const CharacterSet ipChars =  CharacterSet("IP Address",".:") + CharacterSet::HEXDIG;
+
+            // parse  src-IP SP dst-IP SP src-port SP dst-port CRLF
+            if (!tok.prefix(ipa, ipChars) || !tok.skip(' ') ||
+               !tok.prefix(ipb, ipChars) || !tok.skip(' ') ||
+               !tok.int64(porta) || !tok.skip(' ') ||
+               !tok.int64(portb) || !tok.skip('\r') || !tok.skip('\n'))
+                return proxyProtocolError(!tok.atEnd());
+
+            // XXX parse IP and port strings
+            Ip::Address originalClient, originalDest;
+
+            if (!originalClient.GetHostByName(ipa.c_str()))
+                return proxyProtocolError(true);
+
+            if (!originalDest.GetHostByName(ipb.c_str()))
+                return false;
+
+            if (porta > 0 && porta <= 0xFFFF) // max uint16_t
+                originalClient.port(static_cast<uint16_t>(porta));
+            else
+                return proxyProtocolError(true);
+
+            if (portb > 0 && portb <= 0xFFFF) // max uint16_t
+                originalDest.port(static_cast<uint16_t>(portb));
+            else
+                return proxyProtocolError(true);
+
+            in.buf = tok.remaining(); // sync buffers
+            needProxyProtocolHeader_ = false; // found successfully
+
+            // we have original client and destination details now
+            // replace the tcpClient connection values
+            debugs(33, 5, "PROXY protocol on connection " << clientConnection);
+            clientConnection->local = originalDest;
+            clientConnection->remote = originalClient;
+            debugs(33, 5, "PROXY upgrade: " << clientConnection);
+
+            // repeat fetch ensuring the new client FQDN can be logged
+            if (Config.onoff.log_fqdn)
+                fqdncache_gethostbyaddr(clientConnection->remote, FQDN_LOOKUP_IF_MISS);
+
+            return true;
+        }
+
+    } else if (in.buf.length() >= proxy1magic.length()) {
+        // input other than the PROXY header is a protocol error
+        return proxyProtocolError(true);
+    }
+
+    // not enough bytes to parse yet.
+    return false;
+}
+
 /**
  * Attempt to parse one or more requests from the input buffer.
  * If a request is successfully parsed, even if the next request
