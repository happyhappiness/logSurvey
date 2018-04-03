    assert(l);
    switch (which) {
    case HTTP_SVC:
	x = statLogHistDeltaMedian(&l->client_http.all_svc_time, &f->client_http.all_svc_time);
	break;
    case ICP_SVC:
	x = statLogHistDeltaMedian(&l->icp.query_svc_time, &f->icp.query_svc_time);
	break;
    case DNS_SVC:
	x = statLogHistDeltaMedian(&l->dns.svc_time, &f->dns.svc_time);
	break;
    default:
	debug(49, 5) ("get_median_val: unknown type.\n");
	x = 0;
    }
    return (int) x;
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
