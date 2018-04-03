DumpMallocStatistics(StoreEntry* sentry)
{
#if XMALLOC_STATISTICS

    xm_deltat = current_dtime - xm_time;
    xm_time = current_dtime;
    storeAppendPrintf(sentry, "\nMemory allocation statistics\n");
