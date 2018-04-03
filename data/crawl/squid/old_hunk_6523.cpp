    f = dnsData->data;
    if (f->status != FQDN_DISPATCHED)
	fatal_dump("fqdncache_dnsHandleRead: bad status");
    if (strstr(dnsData->ip_inbuf, "$end\n")) {
	/* end of record found */
	DnsStats.replies++;
	statHistCount(&Counter.dns.svc_time,
	    tvSubMsec(dnsData->dispatch_time, current_time));
	if ((x = fqdncache_parsebuffer(dnsData->ip_inbuf, dnsData)) == NULL) {
	    debug(35, 0) ("fqdncache_dnsHandleRead: fqdncache_parsebuffer failed?!\n");
	} else {
	    dnsData->offset = 0;
	    dnsData->ip_inbuf[0] = '\0';
