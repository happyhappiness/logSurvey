	storeAppendPrintf(s, "\t%s %s\n",
	    RequestMethodStr[mem->method], mem->log_url);
    storeAppendPrintf(s, "\t%s\n", describeStatuses(e));
    storeAppendPrintf(s, "\t%s\n", storeEntryFlags(e));
    storeAppendPrintf(s, "\t%s\n", describeTimestamps(e));
    storeAppendPrintf(s, "\t%d locks, %d clients, %d refs\n",
	(int) e->lock_count,
