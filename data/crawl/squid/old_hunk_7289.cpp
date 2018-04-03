	Config.negativeTtl);
    storeAppendPrintf(sentry,
	"{ReadTimeout %d \"# Maximum idle connection (s)\"}\n",
	Config.readTimeout);
    storeAppendPrintf(sentry,
	"{ClientLifetime %d \"# Lifetime for incoming HTTP requests\"}\n",
	Config.lifetimeDefault);
    storeAppendPrintf(sentry,
	"{CleanRate %d \"# Rate for periodic object expiring\"}\n",
	Config.cleanRate);
