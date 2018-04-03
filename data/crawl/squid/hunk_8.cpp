     b->tcp_keepalive = tcp_keepalive;
     b->secure = secure;
 
-#if USE_OPENSSL
-    if (sslContextSessionId)
-        b->sslContextSessionId = xstrdup(sslContextSessionId);
-
-#if 0
-    // TODO: AYJ: 2015-01-15: for now SSL does not clone the context object.
-    // cloning should only be done before the PortCfg is post-configure initialized and opened
-    Security::ContextPointer sslContext;
-#endif
-
-#endif /*0*/
-
     return b;
 }
 
-#if USE_OPENSSL
-void
-AnyP::PortCfg::configureSslServerContext()
-{
-    if (!secure.certs.empty()) {
-        Security::KeyData &keys = secure.certs.front();
-        Ssl::readCertChainAndPrivateKeyFromFiles(signingCert, signPkey, certsToChain, keys.certFile.c_str(), keys.privateKeyFile.c_str());
-    }
-
-    if (!signingCert) {
-        char buf[128];
-        fatalf("No valid signing SSL certificate configured for %s_port %s", AnyP::ProtocolType_str[transport.protocol],  s.toUrl(buf, sizeof(buf)));
-    }
-
-    if (!signPkey)
-        debugs(3, DBG_IMPORTANT, "No SSL private key configured for  " << AnyP::ProtocolType_str[transport.protocol] << "_port " << s);
-
-    Ssl::generateUntrustedCert(untrustedSigningCert, untrustedSignPkey,
-                               signingCert, signPkey);
-
-    if (!untrustedSigningCert) {
-        char buf[128];
-        fatalf("Unable to generate signing SSL certificate for untrusted sites for %s_port %s", AnyP::ProtocolType_str[transport.protocol], s.toUrl(buf, sizeof(buf)));
-    }
-
-    if (!secure.createStaticServerContext(*this)) {
-        char buf[128];
-        fatalf("%s_port %s initialization error", AnyP::ProtocolType_str[transport.protocol], s.toUrl(buf, sizeof(buf)));
-    }
-}
-#endif
-
