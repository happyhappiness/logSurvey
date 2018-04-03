        if (s->sslflags)
            storeAppendPrintf(e, " sslflags=%s", s->sslflags);

        storeAppendPrintf(e, "\n");

        s = (https_port_list *) s->http.next;
