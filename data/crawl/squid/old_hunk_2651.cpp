    Must(entry != NULL);

#if XMALLOC_STATISTICS
    if (UsingSmp() && IamWorkerProcess())
        storeAppendPrintf(entry, "by kid%d {\n", KidIdentifier);
    DumpMallocStatistics(entry);
    if (UsingSmp() && IamWorkerProcess())
        storeAppendPrintf(entry, "} by kid%d\n\n", KidIdentifier);
#endif
    if (IamPrimaryProcess())
