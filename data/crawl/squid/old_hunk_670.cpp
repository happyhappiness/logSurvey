        storeAppendPrintf(e, " ssl-bump");
#endif

    if (!s->secure.certFile.isEmpty())
        storeAppendPrintf(e, " tls-cert=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.certFile));

    if (!s->secure.privateKeyFile.isEmpty() && s->secure.privateKeyFile != s->secure.certFile)
        storeAppendPrintf(e, " tls-key=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.privateKeyFile));

    if (!s->secure.sslOptions.isEmpty())
        storeAppendPrintf(e, " tls-options=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.sslOptions));

    if (!s->secure.sslCipher.isEmpty())
        storeAppendPrintf(e, " tls-cipher=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.sslCipher));

    if (!s->secure.caFile.isEmpty())
        storeAppendPrintf(e, " tls-cafile=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.caFile));

    if (!s->secure.caDir.isEmpty())
        storeAppendPrintf(e, " tls-capath=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.caDir));

    if (!s->secure.crlFile.isEmpty())
        storeAppendPrintf(e, " tls-crlfile=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->secure.crlFile));

#if USE_OPENSSL
    if (s->dhfile)
