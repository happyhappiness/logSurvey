	    storeAppendPrintf(e, " tcp_keepalive");
	}
    }

#if USE_SSL
        if (s->cert)
            storeAppendPrintf(e, " cert=%s", s->cert);

        if (s->key)
            storeAppendPrintf(e, " key=%s", s->key);

        if (s->version)
            storeAppendPrintf(e, " version=%d", s->version);

        if (s->options)
            storeAppendPrintf(e, " options=%s", s->options);

        if (s->cipher)
            storeAppendPrintf(e, " cipher=%s", s->cipher);

        if (s->cafile)
            storeAppendPrintf(e, " cafile=%s", s->cafile);

        if (s->capath)
            storeAppendPrintf(e, " capath=%s", s->capath);

        if (s->crlfile)
            storeAppendPrintf(e, " crlfile=%s", s->crlfile);

        if (s->dhfile)
            storeAppendPrintf(e, " dhparams=%s", s->dhfile);

        if (s->sslflags)
            storeAppendPrintf(e, " sslflags=%s", s->sslflags);

        if (s->sslcontext)
            storeAppendPrintf(e, " sslcontext=%s", s->sslcontext);

        if (s->sslBump)
            storeAppendPrintf(e, " sslBump");
#endif
}

static void
