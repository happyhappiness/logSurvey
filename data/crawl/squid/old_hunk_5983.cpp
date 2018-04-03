    storeAppendPrintf(sentry, "RCODE");
    for (i = 0; i < MAX_ATTEMPT; i++)
	storeAppendPrintf(sentry, " ATTEMPT%d", i + 1);
    for (j = 0; j < MAX_RCODE; j++) {
	storeAppendPrintf(sentry, "%5d", j);
	for (i = 0; i < MAX_ATTEMPT; i++)