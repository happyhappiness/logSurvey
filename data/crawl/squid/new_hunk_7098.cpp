	obj->proto_stat_data[i].kb.now = 0;
    }
    *object = obj;
	for (i=0; i<PCONN_HIST_SZ; i++)
		client_pconn_hist[i] = 0;
}

void
pconnHistCount(int what, int i)
{
    if (i >= PCONN_HIST_SZ)
	i = PCONN_HIST_SZ - 1;
    /* what == 0 for client, 1 for server */
    if (what == 0)
	client_pconn_hist[i]++;
}

void
pconnHistDump(StoreEntry * e)
{
    int i;
    storeAppendPrintf(e,
	"Client-side persistent connection counts:\n"
	"\n"
	"req/\n"
	"conn      count\n"
	"----  ---------\n");
    for (i = 0; i < PCONN_HIST_SZ; i++) {
	if (client_pconn_hist[i] == 0)
	    continue;
	storeAppendPrintf(e, "%4d  %9d\n", i, client_pconn_hist[i]);
    }
}