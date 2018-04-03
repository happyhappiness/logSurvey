	if ((++N & 0xFF) == 0) {
	    debug(18, 3) ("stat_objects_get:  Processed %d objects...\n", N);
	}
	storeAppendPrintf(sentry, "%s %s\n",
	    RequestMethodStr[entry->method], storeUrl(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeStatuses(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeFlags(entry));
