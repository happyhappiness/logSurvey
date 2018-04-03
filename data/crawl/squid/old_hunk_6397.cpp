statCountersHistograms(StoreEntry * sentry)
{
    StatCounters *f = &Counter;
#if TOO_MUCH_OUTPUT
    storeAppendPrintf(sentry, "client_http.all_svc_time histogram:\n");
    statHistDump(&f->client_http.all_svc_time, sentry, NULL);
    storeAppendPrintf(sentry, "client_http.miss_svc_time histogram:\n");
