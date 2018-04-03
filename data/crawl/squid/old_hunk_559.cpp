    s->secure.dumpCfg(e, "tls-");

#if USE_OPENSSL
    if (s->dhfile)
        storeAppendPrintf(e, " dhparams=%s", s->dhfile);

    if (s->tls_dh)
        storeAppendPrintf(e, " tls-dh=%s", s->tls_dh);

    if (s->sslContextSessionId)
        storeAppendPrintf(e, " sslcontext=%s", s->sslContextSessionId);

