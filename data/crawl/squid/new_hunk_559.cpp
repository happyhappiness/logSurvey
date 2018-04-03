    s->secure.dumpCfg(e, "tls-");

#if USE_OPENSSL
    if (s->sslContextSessionId)
        storeAppendPrintf(e, " sslcontext=%s", s->sslContextSessionId);

