     ::Parser::Tokenizer tok(in.buf);
     tok.skip(Proxy1p0magic);
 
-    SBuf tcpVersion;
-    if (!tok.prefix(tcpVersion, CharacterSet::ALPHA+CharacterSet::DIGIT))
-        return proxyProtocolError(tok.atEnd()?"PROXY/1.0 error: invalid protocol family":NULL);
+    static const SBuf unknown("UNKNOWN"), tcpName("TCP");
+    if (tok.skip(tcpName)) {
 
-    if (!tcpVersion.cmp("UNKNOWN")) {
-        // skip to first LF (assumes it is part of CRLF)
-        const SBuf::size_type pos = in.buf.findFirstOf(CharacterSet::LF);
-        if (pos != SBuf::npos) {
-            if (in.buf[pos-1] != '\r')
-                return proxyProtocolError("PROXY/1.0 error: missing CR");
-            // found valid but unusable header
-            in.buf.consume(pos);
-            needProxyProtocolHeader_ = false;
-            return true;
-        }
-        // else, no LF found
-
-        // protocol error only if there are more than 107 bytes prefix header
-        return proxyProtocolError(in.buf.length() > 107? "PROXY/1.0 error: missing CRLF":NULL);
-
-    } else if (!tcpVersion.cmp("TCP",3)) {
+        // skip TCP/IP version number
+        static const CharacterSet tcpVersions("TCP-version","46");
+        if(!tok.skip(tcpVersions))
+            return proxyProtocolError(tok.atEnd() ? "PROXY/1.0 error: missing TCP version" : NULL);
 
         // skip SP after protocol version
         if (!tok.skip(' '))
-            return proxyProtocolError(tok.atEnd()?"PROXY/1.0 error: missing SP":NULL);
+            return proxyProtocolError(tok.atEnd() ? "PROXY/1.0 error: missing SP" : NULL);
 
         SBuf ipa, ipb;
         int64_t porta, portb;
-        const CharacterSet ipChars =  CharacterSet("IP Address",".:") + CharacterSet::HEXDIG;
+        static const CharacterSet ipChars = CharacterSet("IP Address",".:") + CharacterSet::HEXDIG;
+
+        // parse:  src-IP SP dst-IP SP src-port SP dst-port CR
+        // leave the LF until later.
+        const bool correct = tok.prefix(ipa, ipChars) && tok.skip(' ') &&
+                             tok.prefix(ipb, ipChars) && tok.skip(' ') &&
+                             tok.int64(porta) && tok.skip(' ') &&
+                             tok.int64(portb) &&
+                             tok.skip('\r');
+        if (!correct)
+            return proxyProtocolError(!tok.atEnd() ? "PROXY/1.0 error: invalid syntax" : NULL);
 
-        // parse  src-IP SP dst-IP SP src-port SP dst-port CRLF
-        if (!tok.prefix(ipa, ipChars) || !tok.skip(' ') ||
-           !tok.prefix(ipb, ipChars) || !tok.skip(' ') ||
-           !tok.int64(porta) || !tok.skip(' ') ||
-           !tok.int64(portb) || !tok.skip('\r') || !tok.skip('\n'))
-            return proxyProtocolError(!tok.atEnd()?"PROXY/1.0 error: invalid syntax":NULL);
+        if (!tok.skip('\n')) // line terminator.
+            return proxyProtocolError("PROXY/1.0 error: missing LF");
 
         in.buf = tok.remaining(); // sync buffers
         needProxyProtocolHeader_ = false; // found successfully