    DnsStats.replies++;
    dnsData->offset += len;
    dnsData->ip_inbuf[dnsData->offset] = '\0';
    f = dnsData->data;
    if (f->status != FQDN_DISPATCHED)
	fatal_dump("fqdncache_dnsHandleRead: bad status");
    if (strstr(dnsData->ip_inbuf, "$end\n")) {
	/* end of record found */
	svc_time = tvSubMsec(dnsData->dispatch_time, current_time);
