
    storeAppendPrintf(sentry, "{ReadTimeout %d \"# Maximum idle connection (s)\"}\n", getReadTimeout());

    storeAppendPrintf(sentry, "{ClientLifetime %d \"# Lifetime for incoming ascii port requests or outgoing clients (s)\"}\n", getClientLifetime());

    storeAppendPrintf(sentry, "{CleanRate %d \"# Rate for periodic object expiring\"}\n",
	getCleanRate());
