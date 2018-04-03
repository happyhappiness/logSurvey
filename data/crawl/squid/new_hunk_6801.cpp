    storeAppendPrintf(sentry, "cpu_usage = %f%%\n", dpercent(ct, dt));
}

static void
statCounterInit(StatCounters * C)
{
    C->timestamp = current_time;
    /*
     * HTTP svc_time hist is kept in milli-seconds
     */
    statLogHistInit(&C->client_http.svc_time,
	statHttpSvcTimeBin(3600000.0 * 3.0),
	statHttpSvcTimeBin,
	statHttpSvcTimeVal);
    /*
     * ICP svc_time hist is kept in micro-seconds
     */
    statLogHistInit(&C->icp.svc_time,
	statIcpSvcTimeBin(1000000.0 * 60.0),
	statIcpSvcTimeBin,
	statIcpSvcTimeVal);
}

void
statInit(void)
{
