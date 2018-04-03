 #if USE_SSL
 void AnyP::PortCfg::configureSslServerContext()
 {
-    staticSslContext.reset(
-        sslCreateServerContext(cert, key,
-                               version, cipher, options, sslflags, clientca,
-                               cafile, capath, crlfile, dhfile,
-                               sslContextSessionId));
-
-    if (!staticSslContext) {
-        char buf[128];
-        fatalf("%s_port %s initialization error", protocol,  s.ToURL(buf, sizeof(buf)));
-    }
-
-    if (!sslBump)
-        return;
-
     if (cert)
         Ssl::readCertChainAndPrivateKeyFromFiles(signingCert, signPkey, certsToChain, cert, key);
 
