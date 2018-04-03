 }
 
 void
-Security::ServerOptions::createSigningContexts(AnyP::PortCfg &port)
+Security::ServerOptions::createSigningContexts(const AnyP::PortCfg &port)
 {
-    const char *portType = AnyP::ProtocolType_str[port.transport.protocol];
-    if (!certs.empty()) {
-#if USE_OPENSSL
-        Security::KeyData &keys = certs.front();
-        Ssl::readCertChainAndPrivateKeyFromFiles(signingCert, signPkey, certsToChain, keys.certFile.c_str(), keys.privateKeyFile.c_str());
-#else
-        char buf[128];
-        fatalf("Directive '%s_port %s' requires --with-openssl.", portType, port.s.toUrl(buf, sizeof(buf)));
-#endif
-    }
+    // For signing we do not have a pre-initialized context object. Instead
+    // contexts are generated as needed. This method initializes the cert
+    // and key pointers used to sign those contexts later.
 
-    if (!signingCert) {
+    signingCa = certs.front();
+
+    const char *portType = AnyP::ProtocolType_str[port.transport.protocol];
+    if (!signingCa.cert) {
         char buf[128];
-        fatalf("No valid signing SSL certificate configured for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
+        // XXX: we never actually checked that the cert is capable of signing!
+        fatalf("No valid signing certificate configured for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
     }
 
-    if (!signPkey)
-        debugs(3, DBG_IMPORTANT, "No SSL private key configured for  " << portType << "_port " << port.s);
+    if (!signingCa.pkey)
+        debugs(3, DBG_IMPORTANT, "No TLS private key configured for  " << portType << "_port " << port.s);
 
 #if USE_OPENSSL
-    Ssl::generateUntrustedCert(untrustedSigningCert, untrustedSignPkey, signingCert, signPkey);
+    Ssl::generateUntrustedCert(untrustedSigningCa.cert, untrustedSigningCa.pkey, signingCa.cert, signingCa.pkey);
+#elif USE_GNUTLS
+    // TODO: implement for GnuTLS. Just a warning for now since generate is implicitly on for all crypto builds.
+    signingCa.cert.reset();
+    signingCa.pkey.reset();
+    debugs(83, DBG_CRITICAL, "WARNING: Dynamic TLS certificate generation requires --with-openssl.");
+    return;
+#else
+    debugs(83, DBG_CRITICAL, "ERROR: Dynamic TLS certificate generation requires --with-openssl.");
+    return;
 #endif
 
-    if (!untrustedSigningCert) {
+    if (!untrustedSigningCa.cert) {
         char buf[128];
-        fatalf("Unable to generate signing SSL certificate for untrusted sites for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
-    }
-
-    if (!createStaticServerContext(port)) {
-        char buf[128];
-        fatalf("%s_port %s initialization error", portType, port.s.toUrl(buf, sizeof(buf)));
+        fatalf("Unable to generate signing certificate for untrusted sites for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
     }
 }
 
