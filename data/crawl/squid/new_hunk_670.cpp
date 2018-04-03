        storeAppendPrintf(e, " ssl-bump");
#endif

    s->secure.dumpCfg(e, "tls-");

#if USE_OPENSSL
    if (s->dhfile)
