	    debug(18, 3) ("stat_objects_get:  Processed %d objects...\n", N);
	}
	storeAppendPrintf(sentry, "%s %s\n",
	    RequestMethodStr[entry->method], entry->url);
	storeAppendPrintf(sentry, "\t%s\n", describeStatuses(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeFlags(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeTimestamps(entry));
