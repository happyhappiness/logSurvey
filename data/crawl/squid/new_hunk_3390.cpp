    }

#if USE_SSL
    if (s->sslBump)
        storeAppendPrintf(e, " sslBump");

    if (s->cert)
        storeAppendPrintf(e, " cert=%s", s->cert);

