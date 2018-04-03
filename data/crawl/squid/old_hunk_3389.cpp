                      n,
                      s->s.ToURL(buf,MAX_IPSTRLEN));

    if (s->defaultsite)
        storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);

    if (s->intercepted)
        storeAppendPrintf(e, " intercept");

    if (s->vhost)
        storeAppendPrintf(e, " vhost");

    if (s->vport)
        storeAppendPrintf(e, " vport");

    if (s->connection_auth_disabled)
        storeAppendPrintf(e, " connection-auth=off");
    else
