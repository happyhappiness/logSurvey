
#define XAVG(X) (dt ? (double) (f->X - l->X) / dt : 0.0)
static void
statAvgDump(StoreEntry * sentry, int minutes, int hours)
{
    StatCounters *f;
    StatCounters *l;
    double dt;
    double ct;
    double x;
    assert(N_COUNT_HIST > 1);
    assert(minutes > 0 || hours > 0);
    f = &CountHist[0];
    l = f;
    if (minutes > 0 && hours == 0) {
	/* checking minute readings ... */
	if (minutes > N_COUNT_HIST - 1)
	    minutes = N_COUNT_HIST - 1;
	l = &CountHist[minutes];
    } else if (minutes == 0 && hours > 0) {
	/* checking hour readings ... */
	if (hours > N_COUNT_HOUR_HIST - 1)
	    hours = N_COUNT_HOUR_HIST - 1;
	l = &CountHourHist[hours];
    } else {
	debug(18,1)("statAvgDump: Invalid args, minutes=%d, hours=%d\n",
		minutes, hours);
	return;
    }
    dt = tvSubDsec(l->timestamp, f->timestamp);
    ct = f->cputime - l->cputime;

     storeAppendPrintf(sentry, "sample_start_time = %d.%d (%s)\n",
        f->timestamp.tv_sec,
	f->timestamp.tv_usec,
	mkrfc1123(f->timestamp.tv_sec));
     storeAppendPrintf(sentry, "sample_end_time = %d.%d (%s)\n",
        l->timestamp.tv_sec,
	l->timestamp.tv_usec,
	mkrfc1123(l->timestamp.tv_sec));

    storeAppendPrintf(sentry, "client_http.requests = %f/sec\n",
	XAVG(client_http.requests));
    storeAppendPrintf(sentry, "client_http.hits = %f/sec\n",
