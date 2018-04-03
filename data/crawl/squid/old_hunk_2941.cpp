    for (i = 0; i < MAX_ATTEMPT; i++)
        storeAppendPrintf(sentry, " ATTEMPT%d", i + 1);

    storeAppendPrintf(sentry, "\n");

    for (j = 0; j < MAX_RCODE; j++) {
        storeAppendPrintf(sentry, "%5d", j);

        for (i = 0; i < MAX_ATTEMPT; i++)
            storeAppendPrintf(sentry, " %8d", RcodeMatrix[j][i]);

        storeAppendPrintf(sentry, "\n");
    }

    if (npc) {
