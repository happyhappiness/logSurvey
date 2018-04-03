int client_pconn_hist[PCONN_HIST_SZ];
int server_pconn_hist[PCONN_HIST_SZ];

/*
 * An hour's worth, plus the 'current' counter
 */
#define N_COUNT_HIST 61
static StatCounters CountHist[N_COUNT_HIST];
static int NCountHist = 0;

void
stat_utilization_get(StoreEntry * e)
{
	/* MAKE SOMETHING UP */
}

void
