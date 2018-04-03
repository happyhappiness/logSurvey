    storeAppendPrintf(sentry, "cpu_usage = %f%%\n", dpercent(ct, dt));
}

void
statInit(void)
{
    int i;
    debug(18, 5) ("statInit: Initializing...\n");
    memset(CountHist, '\0', N_COUNT_HIST * sizeof(StatCounters));
    for (i = 0; i < N_COUNT_HIST; i++)
	statCountersInit(&CountHist[i]);
    statCountersInit(&Counter);
    eventAdd("statAvgTick", statAvgTick, NULL, 60);
    cachemgrRegister("info",
	"General Runtime Information",
