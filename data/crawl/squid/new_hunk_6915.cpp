    dnsData->offset += len;
    dnsData->ip_inbuf[dnsData->offset] = '\0';
    i = dnsData->data;
    assert(i != NULL);
    assert(i->status == IP_DISPATCHED);
    if (strstr(dnsData->ip_inbuf, "$end\n")) {
	/* end of record found */
	IpcacheStats.avg_svc_time = intAverage(IpcacheStats.avg_svc_time,
