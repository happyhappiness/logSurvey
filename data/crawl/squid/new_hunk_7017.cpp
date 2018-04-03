    int N = 0;
    int i;
    struct _store_client *sc;
    for (entry = storeGetFirst(); entry != NULL; entry = storeGetNext()) {
	mem = entry->mem_obj;
	if (vm_or_not && mem == NULL)
	    continue;
	if ((++N & 0xFF) == 0) {
	    debug(18, 3) ("stat_objects_get:  Processed %d objects...\n", N);
	}
	storeAppendPrintf(sentry, "%s %s\n",
	    RequestMethodStr[entry->method], entry->url);
	storeAppendPrintf(sentry, "\t%s\n", describeStatuses(entry));
