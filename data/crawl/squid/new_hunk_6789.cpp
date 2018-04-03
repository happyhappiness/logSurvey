}

static void
statLogHistDump(StoreEntry * sentry, StatLogHist * H)
{
    int i;
    for (i = 0; i < STAT_LOG_HIST_BINS; i++) {
	if (H->bins[i] == 0)
	    continue;
	storeAppendPrintf(sentry, "\t%3d/%f\t%d\n",
	    i,
	    statLogHistVal(H, 0.5 + i),
	    H->bins[i]);
    }
}
