    if (s->defaultsite)
        storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);

    if (s->transparent)
        storeAppendPrintf(e, " transparent");

    if (s->vhost)
        storeAppendPrintf(e, " vhost");
