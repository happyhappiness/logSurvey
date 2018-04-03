     }
 }
 
-// XXX: make a GnuTLS variant
-Security::ContextPointer
+Security::ContextPtr
+Security::PeerOptions::createBlankContext() const
+{
+    Security::ContextPtr t = nullptr;
+
+#if USE_OPENSSL
+    Ssl::Initialize();
+
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+    t = SSL_CTX_new(TLS_client_method());
+#else
+    t = SSL_CTX_new(SSLv23_client_method());
+#endif
+    if (!t) {
+        const auto x = ERR_error_string(ERR_get_error(), nullptr);
+        fatalf("Failed to allocate TLS client context: %s\n", x);
+    }
+
+#elif USE_GNUTLS
+    // Initialize for X.509 certificate exchange
+    if (const int x = gnutls_certificate_allocate_credentials(&t)) {
+        fatalf("Failed to allocate TLS client context: error=%d\n", x);
+    }
+
+#else
+    fatal("Failed to allocate TLS client context: No TLS library\n");
+
+#endif
+
+    return t;
+}
+
+Security::ContextPtr
 Security::PeerOptions::createClientContext(bool setOptions)
 {
-    Security::ContextPointer t = nullptr;
+    Security::ContextPtr t = nullptr;
 
     updateTlsVersionLimits();
 
 #if USE_OPENSSL
     // XXX: temporary performance regression. c_str() data copies and prevents this being a const method
-    t = sslCreateClientContext(certFile.c_str(), privateKeyFile.c_str(), sslCipher.c_str(),
-                               (setOptions ? parsedOptions : 0), parsedFlags);
+    t = sslCreateClientContext(*this, (setOptions ? parsedOptions : 0), parsedFlags);
+
+#elif USE_GNUTLS && WHEN_READY_FOR_GNUTLS
+    t = createBlankContext();
+
 #endif
 
     if (t) {
