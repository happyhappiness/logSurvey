	    fwdStateFree(fwdState);
    }
}

void
fwdInit(void)
{
	cachemgrRegister("forward",
		"Request Forwarding Statistics",
		fwdStats, 0, 1);
}

static void
fwdLogReplyStatus(int tries, http_status status)
{
    if (status > HTTP_INVALID_HEADER)
	return;
    assert(tries);
    tries--;
    if (tries > MAX_FWD_STATS_IDX)
	tries = MAX_FWD_STATS_IDX;
    FwdReplyCodes[tries][status]++;
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
