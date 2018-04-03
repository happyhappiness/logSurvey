
#if USE_ICMP
    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
	"Network Data Entries",
	meta_data.netdb,
	(int) sizeof(netdbEntry),
	(int) (meta_data.netdb * sizeof(netdbEntry) >> 10));
#endif

    storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",