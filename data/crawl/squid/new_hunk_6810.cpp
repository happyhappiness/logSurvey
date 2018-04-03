}

void
statCounters(StoreEntry * e)
{
    statCountersDump(e);
}

void
statAvg5min(StoreEntry * e)
{
    statAvgDump(e, 5);
}

void
statAvg60min(StoreEntry * e)
{
    statAvgDump(e, 60);
}