	    nameservers[i].nqueries,
	    nameservers[i].nreplies);
    }
    storeAppendPrintf(sentry, "\nRcode Matrix:\n");
    storeAppendPrintf(sentry, "RCODE");
    for (i = 0; i < MAX_ATTEMPT; i++)
	storeAppendPrintf(sentry, " ATTEMPT%d", i + 1);
    for (j = 0; j < MAX_RCODE; j++) {
	storeAppendPrintf(sentry, "%5d", j);
	for (i = 0; i < MAX_ATTEMPT; i++)
	    storeAppendPrintf(sentry, " %8d", RcodeMatrix[j][i]);
	storeAppendPrintf(sentry, "\n");
    }
}

static void
