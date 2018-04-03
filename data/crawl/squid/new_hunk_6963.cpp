void
info_get(StoreEntry * sentry)
{
    struct rusage rusage;
    double cputime;
    double runtime;
#if HAVE_MSTATS && HAVE_GNUMALLOC_H
    struct mstats ms;
#elif HAVE_MALLINFO
    struct mallinfo mp;
    int t;
#endif

    runtime = tvSubDsec(squid_start, current_time);
    if (runtime == 0.0)
	runtime = 1.0;
    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Squid Object Cache: Version %s}\n",
	version_string);
    storeAppendPrintf(sentry, "{Start Time:\t%s}\n",
	mkrfc1123(squid_start.tv_sec));
    storeAppendPrintf(sentry, "{Current Time:\t%s}\n",
	mkrfc1123(current_time.tv_sec));
    storeAppendPrintf(sentry, "{Connection information for %s:}\n",
	appname);
    storeAppendPrintf(sentry, "{\tNumber of HTTP requests received:\t%u}\n",
	Counter.client_http.requests);
    storeAppendPrintf(sentry, "{\tNumber of ICP messages received:\t%u}\n",
	Counter.icp.pkts_recv);
    storeAppendPrintf(sentry, "{\tNumber of ICP messages sent:\t%u}\n",
	Counter.icp.pkts_sent);

    storeAppendPrintf(sentry, "{\tHTTP requests per minute:\t%.1f}\n",
	Counter.client_http.requests / (runtime / 60.0));
    storeAppendPrintf(sentry, "{\tICP messages per minute:\t%.1f}\n",
	(Counter.icp.pkts_sent + Counter.icp.pkts_recv) / (runtime / 60.0));
    storeAppendPrintf(sentry, "{\tSelect loop called: %d times, %0.3f ms avg}\n",
	Counter.select_loops, 1000.0 * runtime / Counter.select_loops);

    storeAppendPrintf(sentry, "{Cache information for %s:}\n",
	appname);
