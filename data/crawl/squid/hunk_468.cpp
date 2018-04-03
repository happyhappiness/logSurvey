 }
 #endif
 
-SSL_CTX *
-sslCreateClientContext(const char *certfile, const char *keyfile, const char *cipher, long options, long fl)
+Security::ContextPtr
+sslCreateClientContext(Security::PeerOptions &peer, long options, long fl)
 {
-    ssl_initialize();
-
-#if (OPENSSL_VERSION_NUMBER >= 0x10100000L)
-    SSL_CTX *sslContext = SSL_CTX_new(TLS_client_method());
-#else
-    SSL_CTX *sslContext = SSL_CTX_new(SSLv23_client_method());
-#endif
-
-    if (sslContext == NULL) {
-        const int ssl_error = ERR_get_error();
-        fatalf("Failed to allocate SSL context: %s\n",
-               ERR_error_string(ssl_error, NULL));
-    }
+    Security::ContextPtr sslContext(peer.createBlankContext());
+    if (!sslContext)
+        return nullptr;
 
     SSL_CTX_set_options(sslContext, options);
 
 #if defined(SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS)
     SSL_CTX_set_info_callback(sslContext, ssl_info_cb);
 #endif
 
-    if (*cipher) {
-        debugs(83, 5, "Using chiper suite " << cipher << ".");
+    if (!peer.sslCipher.isEmpty()) {
+        debugs(83, 5, "Using chiper suite " << peer.sslCipher << ".");
 
+        const char *cipher = peer.sslCipher.c_str();
         if (!SSL_CTX_set_cipher_list(sslContext, cipher)) {
             const int ssl_error = ERR_get_error();
             fatalf("Failed to set SSL cipher suite '%s': %s\n",
                    cipher, ERR_error_string(ssl_error, NULL));
         }
     }
 
-    if (*certfile) {
-        debugs(83, DBG_IMPORTANT, "Using certificate in " << certfile);
+    // TODO: support loading multiple cert/key pairs
+    auto &keys = peer.certs.front();
+    if (!keys.certFile.isEmpty()) {
+        debugs(83, DBG_IMPORTANT, "Using certificate in " << keys.certFile);
 
+        const char *certfile = keys.certFile.c_str();
         if (!SSL_CTX_use_certificate_chain_file(sslContext, certfile)) {
             const int ssl_error = ERR_get_error();
             fatalf("Failed to acquire SSL certificate '%s': %s\n",
                    certfile, ERR_error_string(ssl_error, NULL));
         }
 
-        debugs(83, DBG_IMPORTANT, "Using private key in " << keyfile);
+        debugs(83, DBG_IMPORTANT, "Using private key in " << keys.privateKeyFile);
+        const char *keyfile = keys.privateKeyFile.c_str();
         ssl_ask_password(sslContext, keyfile);
 
         if (!SSL_CTX_use_PrivateKey_file(sslContext, keyfile, SSL_FILETYPE_PEM)) {
