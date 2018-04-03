
    if (s->sslcontext)
        storeAppendPrintf(e, " sslcontext=%s", s->sslcontext);

    if (s->sslBump)
        storeAppendPrintf(e, " sslBump");
#endif
}

