    int k;
    int i;
    storeAppendPrintf(sentry, "{Network DB Statistics:\n");
    storeAppendPrintf(sentry, "{%-16.16s %9s %7s %5s %s}\n",
	"Network",
	"recv/sent",
	"RTT",
