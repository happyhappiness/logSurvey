dump_https_port_list(StoreEntry * e, const char *n, const https_port_list * s)
{
    while (s) {
	storeAppendPrintf(e, "%s %s:%d cert=\"%s\" key=\"%s\"\n",
	    n,
	    inet_ntoa(s->s.sin_addr),
	    ntohs(s->s.sin_port),
	    s->cert,
	    s->key);
	s = s->next;
    }
}
