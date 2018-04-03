{
    assert(poolCount < MAX_NUM_PCONN_POOLS);
    *(pools+poolCount) = aPool;
    poolCount++;
}

void
PconnModule::dump(StoreEntry *e)
{
    int i;

    for (i = 0; i < poolCount; i++) {
        storeAppendPrintf(e, "\n Pool %d Stats\n", i);
        (*(pools+i))->dumpHist(e);
        storeAppendPrintf(e, "\n Pool %d Hash Table\n",i);
