static void
dump_https_port_list(StoreEntry * e, const char *n, const https_port_list * s)
{
    dump_http_port_list(e, n, s);
}

static void
free_https_port_list(https_port_list ** head)
{
    free_http_port_list((http_port_list**)head);
}

#if 0