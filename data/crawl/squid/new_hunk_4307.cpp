    if (s->defaultsite)
        storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);

    if (s->intercepted)
        storeAppendPrintf(e, " intercept");

    if (s->vhost)
        storeAppendPrintf(e, " vhost");
