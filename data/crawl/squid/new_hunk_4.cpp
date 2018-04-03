}

void
Security::ServerOptions::createSigningContexts(const AnyP::PortCfg &port)
{
    // For signing we do not have a pre-initialized context object. Instead
    // contexts are generated as needed. This method initializes the cert
    // and key pointers used to sign those contexts later.

    signingCa = certs.front();

    const char *portType = AnyP::ProtocolType_str[port.transport.protocol];
    if (!signingCa.cert) {
        char buf[128];
        // XXX: we never actually checked that the cert is capable of signing!
        fatalf("No valid signing certificate configured for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
    }

    if (!signingCa.pkey)
        debugs(3, DBG_IMPORTANT, "No TLS private key configured for  " << portType << "_port " << port.s);

#if USE_OPENSSL
    Ssl::generateUntrustedCert(untrustedSigningCa.cert, untrustedSigningCa.pkey, signingCa.cert, signingCa.pkey);
#elif USE_GNUTLS
    // TODO: implement for GnuTLS. Just a warning for now since generate is implicitly on for all crypto builds.
    signingCa.cert.reset();
    signingCa.pkey.reset();
    debugs(83, DBG_CRITICAL, "WARNING: Dynamic TLS certificate generation requires --with-openssl.");
    return;
#else
    debugs(83, DBG_CRITICAL, "ERROR: Dynamic TLS certificate generation requires --with-openssl.");
    return;
#endif

    if (!untrustedSigningCa.cert) {
        char buf[128];
        fatalf("Unable to generate signing certificate for untrusted sites for %s_port %s", portType, port.s.toUrl(buf, sizeof(buf)));
    }
}

