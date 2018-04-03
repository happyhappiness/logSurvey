	if (vm_or_not && mem == NULL)
	    continue;
	if ((++N & 0xFF) == 0) {
	    debug(18, 3) ("stat_objects_get:  Processed %d objects...\n", N);
	}
	storeBuffer(sentry);
	storeAppendPrintf(sentry, "KEY %s\n", storeKeyText(entry->key));
