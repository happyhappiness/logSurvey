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
