    dnsData->offset += len;
    dnsData->ip_inbuf[dnsData->offset] = '\0';
    f = dnsData->data;
    assert(f->status == FQDN_DISPATCHED);
    if (strchr(dnsData->ip_inbuf, '\n')) {
	/* end of record found */
	DnsStats.replies++;
