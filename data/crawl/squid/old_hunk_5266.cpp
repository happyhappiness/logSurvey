        if (s->capath)
            storeAppendPrintf(e, " capath=%s", s->capath);

        if (s->sslflags)
            storeAppendPrintf(e, " sslflags=%s", s->sslflags);

