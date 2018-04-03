dump_https_port_list(StoreEntry * e, const char *n, const https_port_list * s)
{
    while (s) {
	storeAppendPrintf(e, "%s %s:%d cert=\"%s\" key=\"%s\"",
	    n,
	    inet_ntoa(s->s.sin_addr),
	    ntohs(s->s.sin_port),
	    s->cert,
	    s->key);
	if (s->version)
	    storeAppendPrintf(e, " version=%d", s->version);
	if (s->options)
	    storeAppendPrintf(e, " options=%s", s->options);
	if (s->cipher)
	    storeAppendPrintf(e, " cipher=%s", s->cipher);
	storeAppendPrintf(e, "\n");
	s = s->next;
    }
}
