     return ctx;
 }
 
+void
+Security::ServerOptions::initServerContexts(AnyP::PortCfg &port)
+{
+    const char *portType = AnyP::ProtocolType_str[port.transport.protocol];
+    for (auto &keyData : certs) {
+        keyData.loadFromFiles(port, portType);
+    }
+
+    if (generateHostCertificates) {
+        createSigningContexts(port);
+
+    } else if (!createStaticServerContext(port)) {
+        char buf[128];
+        fatalf("%s_port %s initialization error", portType, port.s.toUrl(buf, sizeof(buf)));
+    }
+}
+
 bool
 Security::ServerOptions::createStaticServerContext(AnyP::PortCfg &port)
 {
     updateTlsVersionLimits();
 
     Security::ContextPointer t(createBlankContext());
     if (t) {
+
 #if USE_OPENSSL
-        if (!Ssl::InitServerContext(t, port))
+        if (certs.size() > 1) {
+            // NOTE: calling SSL_CTX_use_certificate() repeatedly _replaces_ the previous cert details.
+            //       so we cannot use it and support multiple server certificates with OpenSSL.
+            debugs(83, DBG_CRITICAL, "ERROR: OpenSSL does not support multiple server certificates. Ignoring addional cert= parameters.");
+        }
+
+        const auto &keys = certs.front();
+
+        if (!SSL_CTX_use_certificate(t.get(), keys.cert.get())) {
+            const auto x = ERR_get_error();
+            debugs(83, DBG_CRITICAL, "ERROR: Failed to acquire TLS certificate '" << keys.certFile << "': " << Security::ErrorString(x));
             return false;
+        }
+
+        if (!SSL_CTX_use_PrivateKey(t.get(), keys.pkey.get())) {
+            const auto x = ERR_get_error();
+            debugs(83, DBG_CRITICAL, "ERROR: Failed to acquire TLS private key '" << keys.privateKeyFile << "': " << Security::ErrorString(x));
+            return false;
+        }
+
+        for (auto cert : keys.chain) {
+            if (SSL_CTX_add_extra_chain_cert(t.get(), cert.get())) {
+                // increase the certificate lock
+                X509_up_ref(cert.get());
+            } else {
+                const auto error = ERR_get_error();
+                debugs(83, DBG_IMPORTANT, "WARNING: can not add certificate to SSL context chain: " << Security::ErrorString(error));
+            }
+        }
+
+#elif USE_GNUTLS
+        for (auto &keys : certs) {
+            gnutls_x509_crt_t crt = keys.cert.get();
+            gnutls_x509_privkey_t xkey = keys.pkey.get();
+            const auto x = gnutls_certificate_set_x509_key(t.get(), &crt, 1, xkey);
+            if (x != GNUTLS_E_SUCCESS) {
+                SBuf whichFile = keys.certFile;
+                if (keys.certFile != keys.privateKeyFile) {
+                    whichFile.appendf(" and ");
+                    whichFile.append(keys.privateKeyFile);
+                }
+                debugs(83, DBG_CRITICAL, "ERROR: Failed to initialize server context with keys from " << whichFile << ": " << Security::ErrorString(x));
+                return false;
+            }
+                // XXX: add cert chain to the context
+        }
 #endif
+
+        if (!updateContextConfig(t)) {
+            debugs(83, DBG_CRITICAL, "ERROR: Configuring static TLS context");
+            return false;
+        }
+
         if (!loadClientCaFile())
             return false;
     }
