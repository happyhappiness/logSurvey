    if (s->sslflags)
        storeAppendPrintf(e, " sslflags=%s", s->sslflags);

    if (s->sslcontext)
        storeAppendPrintf(e, " sslcontext=%s", s->sslcontext);
#endif
}

