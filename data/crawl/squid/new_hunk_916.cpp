    if (s->dhfile)
        storeAppendPrintf(e, " dhparams=%s", s->dhfile);

    if (!s->sslflags.isEmpty())
        storeAppendPrintf(e, " sslflags=" SQUIDSBUFPH, SQUIDSBUFPRINT(s->sslflags));

    if (s->sslContextSessionId)
        storeAppendPrintf(e, " sslcontext=%s", s->sslContextSessionId);
