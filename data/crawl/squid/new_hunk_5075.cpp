        if (s->sslflags)
            storeAppendPrintf(e, " sslflags=%s", s->sslflags);

        if (s->sslcontext)
            storeAppendPrintf(e, " sslcontext=%s", s->sslcontext);

        storeAppendPrintf(e, "\n");

        s = (https_port_list *) s->http.next;
