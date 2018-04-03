	IpcacheStats.release_locked);
    storeAppendPrintf(sentry, "\n\n");
    storeAppendPrintf(sentry, "IP Cache Contents:\n\n");
    storeAppendPrintf(sentry, " %-29.29s %5s %6s %6s %1s\n",
	"Hostname",
	"Flags",
	"lstref",
	"TTL",
	"N");
