static void
dump_generic_http_port(StoreEntry * e, const char *n, const http_port_list * s)
{
    storeAppendPrintf(e, "%s %s:%d",
                      n,
                      inet_ntoa(s->s.sin_addr),
                      ntohs(s->s.sin_port));

    if (s->defaultsite)
        storeAppendPrintf(e, " defaultsite=%s", s->defaultsite);
