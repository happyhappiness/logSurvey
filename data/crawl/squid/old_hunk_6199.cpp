}

static void
fwdStats(StoreEntry *s)
{
	int i;
	int j;
	for (i=0; i<=(int) HTTP_INVALID_HEADER; i++) {
		storeAppendPrintf(s, "%3d", i);
		for (j=0; j<=MAX_FWD_STATS_IDX; j++) {
		    storeAppendPrintf(s, "\t%d", FwdReplyCodes[j][i]);
		}
		storeAppendPrintf(s, "\n");
	}
}