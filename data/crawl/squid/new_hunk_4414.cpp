static void
dump_generic_http_port(StoreEntry * e, const char *n, const http_port_list * s)
{
    char buf[MAX_IPSTRLEN];

    storeAppendPrintf(e, "%s %s",
                      n,
                      s->s.ToURL(buf,MAX_IPSTRLEN));

    if (s->defaultsite)
        storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);
