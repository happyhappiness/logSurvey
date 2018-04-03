    dnsData->offset += len;
    dnsData->ip_inbuf[dnsData->offset] = '\0';
    f = dnsData->data;
    if (f->status != FQDN_DISPATCHED)
	fatal_dump("fqdncache_dnsHandleRead: bad status");
    if (strchr(dnsData->ip_inbuf, '\n')) {
	/* end of record found */
	DnsStats.replies++;
