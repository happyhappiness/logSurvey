}

void
statAvg5min(StoreEntry *e)
{
#if NOT_YET
	statCountersDump(e);
	storeAppendPrintf(e, "\n");
#endif
	statAvgDump(e, 5);
}

void
statAvg60min(StoreEntry *e)
{
#if NOT_YET
	statCountersDump(e);
	storeAppendPrintf(e, "\n");
#endif
	statAvgDump(e, 60);
}
