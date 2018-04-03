	DnsStats.replies);
    storeAppendPrintf(sentry, "number of dnsservers: %d\n",
	NDnsServersAlloc);
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "%7s\t%7s\t%11s\t%s\t%7s\t%7s\n",
	"#",
	"FD",
	"# Requests",
	"Flags",
	"Time",
	"Offset");
    for (k = 0; k < NDnsServersAlloc; k++) {
	dns = *(dns_child_table + k);
	storeAppendPrintf(sentry, "%7d\t%7d\t%11d\t%c%c%c%c\t%7.3f\t%7d\n",
	    k + 1,
	    dns->inpipe,
	    DnsStats.hist[k],
	    EBIT_TEST(dns->flags, HELPER_ALIVE) ? 'A' : ' ',
	    EBIT_TEST(dns->flags, HELPER_BUSY) ? 'B' : ' ',
	    EBIT_TEST(dns->flags, HELPER_CLOSING) ? 'C' : ' ',
	    EBIT_TEST(dns->flags, HELPER_SHUTDOWN) ? 'S' : ' ',
	    0.001 * tvSubMsec(dns->dispatch_time, current_time),
	    (int) dns->offset);
    }
    storeAppendPrintf(sentry, "\nFlags key:\n\n");