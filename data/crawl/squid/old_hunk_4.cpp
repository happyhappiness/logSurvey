}

void
Security::ServerOptions::createSigningContexts(AnyP::PortCfg &port)
{
    const char *portType = AnyP::ProtocolType_str[port.transport.protocol];
    if (!certs.empty()) {
#if USE_OPENSSL
        Security::KeyData &keys = certs.front();
        Ssl::readCertChainAndPrivateKeyFromFiles(signingCert, signPkey, certsToChain, keys.certFile.c_str(), keys.privateKeyFile.c_str());
#else
        char buf[128];
        fatalf("Directive '%s_port %s' requires --with-openssl.", portType, port.s.toUrl(buf, sizeof(buf)));
#endif
    }

    if (!signingCert) {
        char buf[128];
        fatalf("No valid signing SSL certificate configured for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
    }

    if (!signPkey)
        debugs(3, DBG_IMPORTANT, "No SSL private key configured for  " << portType << "_port " << port.s);

#if USE_OPENSSL
    Ssl::generateUntrustedCert(untrustedSigningCert, untrustedSignPkey, signingCert, signPkey);
#endif

    if (!untrustedSigningCert) {
        char buf[128];
        fatalf("Unable to generate signing SSL certificate for untrusted sites for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
    }

    if (!createStaticServerContext(port)) {
        char buf[128];
        fatalf("%s_port %s initialization error", portType, port.s.toUrl(buf, sizeof(buf)));
    }
}

