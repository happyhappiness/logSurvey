        if (s->capath)
            storeAppendPrintf(e, " capath=%s", s->capath);

        if (s->crlfile)
            storeAppendPrintf(e, " crlfile=%s", s->crlfile);

        if (s->dhfile)
            storeAppendPrintf(e, " dhparams=%s", s->dhfile);

