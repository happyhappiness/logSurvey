    }

#if USE_SSL
    if (s->cert)
        storeAppendPrintf(e, " cert=%s", s->cert);

