    safe_free(sslContextSessionId);
#endif
}

#if USE_SSL
void http_port_list::configureSslServerContext()
{
    staticSslContext.reset(
        sslCreateServerContext(cert, key,
                               version, cipher, options, sslflags, clientca,
                               cafile, capath, crlfile, dhfile,
                               sslContextSessionId));

    if (!staticSslContext) {
        char buf[128];
        fatalf("%s_port %s initialization error", protocol,  s.ToURL(buf, sizeof(buf)));
    }

    if (!sslBump)
        return;

    if (cert)
        Ssl::readCertChainAndPrivateKeyFromFiles(signingCert, signPkey, certsToChain, cert, key);

    if (!signingCert) {
        char buf[128];
        fatalf("No valid signing SSL certificate configured for %s_port %s", protocol,  s.ToURL(buf, sizeof(buf)));
    }

    if (!signPkey)
        debugs(3, DBG_IMPORTANT, "No SSL private key configured for  " <<  protocol << "_port " << s);

    Ssl::generateUntrustedCert(untrustedSigningCert, untrustedSignPkey,
                               signingCert, signPkey);

    if (!untrustedSigningCert) {
        char buf[128];
        fatalf("Unable to generate  signing SSL certificate for untrusted sites for %s_port %s", protocol, s.ToURL(buf, sizeof(buf)));
    }
}
#endif
