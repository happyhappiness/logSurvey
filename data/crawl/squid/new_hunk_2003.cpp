}

void
dump_peer_options(StoreEntry * sentry, CachePeer * p)
{
    if (p->options.proxy_only)
        storeAppendPrintf(sentry, " proxy-only");
