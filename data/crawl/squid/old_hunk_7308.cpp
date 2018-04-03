dnsStats(StoreEntry * sentry)
{
    int k;

    storeAppendPrintf(sentry, "{DNSServer Statistics:\n");
    storeAppendPrintf(sentry, "{dnsserver requests: %d}\n",
	DnsStats.requests);
