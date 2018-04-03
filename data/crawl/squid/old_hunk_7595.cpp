		break;
	e = *(list + i);
	if (storeCheckPurgeMem(e)) {
		storePurgeMem(e);
		n_purged++;
	} else if (!storeEntryLocked(e)) {
		storeRelease(e);
		n_released++;
	} else {
		fatal_dump("storeGetMemSpace: Bad Entry in LRU list");
	}
    }

