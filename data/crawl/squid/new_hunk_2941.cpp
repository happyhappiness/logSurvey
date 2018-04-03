    for (i = 0; i < MAX_ATTEMPT; i++)
        storeAppendPrintf(sentry, " ATTEMPT%d", i + 1);

    storeAppendPrintf(sentry, " PROBLEM\n");

    for (j = 0; j < MAX_RCODE; j++) {
        if (j > 10 && j < 16)
            continue; // unassigned by IANA.

        storeAppendPrintf(sentry, "%5d", j);

        for (i = 0; i < MAX_ATTEMPT; i++)
            storeAppendPrintf(sentry, " %8d", RcodeMatrix[j][i]);

        storeAppendPrintf(sentry, " : %s\n",Rcodes[j]);
    }

    if (npc) {
