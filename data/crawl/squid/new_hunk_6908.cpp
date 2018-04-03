	}
	storeBuffer(sentry);
	storeAppendPrintf(sentry, "KEY %s\n", storeKeyText(entry->key));
	if (mem)
	    storeAppendPrintf(sentry, "\t%s %s\n",
		RequestMethodStr[mem->method], mem->url);
	storeAppendPrintf(sentry, "\t%s\n", describeStatuses(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeFlags(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeTimestamps(entry));
