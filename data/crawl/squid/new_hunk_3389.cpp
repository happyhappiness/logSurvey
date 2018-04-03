                      n,
                      s->s.ToURL(buf,MAX_IPSTRLEN));

    if (s->intercepted)
        storeAppendPrintf(e, " intercept");

    if (s->spoof_client_ip)
        storeAppendPrintf(e, " tproxy");

    if (s->accel)
        storeAppendPrintf(e, " accel");

    if (s->vhost)
        storeAppendPrintf(e, " vhost");

    if (s->vport)
        storeAppendPrintf(e, " vport");

    if (s->defaultsite)
        storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);

    if (s->connection_auth_disabled)
        storeAppendPrintf(e, " connection-auth=off");
    else
