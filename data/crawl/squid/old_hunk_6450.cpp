    return buf;
}

/* process objects list */
static void
statObjects(StoreEntry * sentry, int vm_or_not)
{
    StoreEntry *entry = NULL;
    StoreEntry *next = NULL;
    MemObject *mem;
    int N = 0;
    int i;
    struct _store_client *sc;
    next = (StoreEntry *) hash_first(store_table);
    while ((entry = next) != NULL) {
	next = (StoreEntry *) hash_next(store_table);
	mem = entry->mem_obj;
	if (vm_or_not && mem == NULL)
	    continue;
	if ((++N & 0xFF) == 0) {
	    debug(18, 3) ("statObjects:  Processed %d objects...\n", N);
	}
	storeBuffer(sentry);
	storeAppendPrintf(sentry, "KEY %s\n", storeKeyText(entry->key));
	if (mem)
	    storeAppendPrintf(sentry, "\t%s %s\n",
		RequestMethodStr[mem->method], mem->log_url);
	storeAppendPrintf(sentry, "\t%s\n", describeStatuses(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeFlags(entry));
	storeAppendPrintf(sentry, "\t%s\n", describeTimestamps(entry));
	storeAppendPrintf(sentry, "\t%d locks, %d clients, %d refs\n",
	    (int) entry->lock_count,
	    storePendingNClients(entry),
	    (int) entry->refcount);
	storeAppendPrintf(sentry, "\tSwap File %#08X\n",
	    entry->swap_file_number);
	if (mem == NULL)
	    continue;
	storeAppendPrintf(sentry, "\tinmem_lo: %d\n", (int) mem->inmem_lo);
	storeAppendPrintf(sentry, "\tinmem_hi: %d\n", (int) mem->inmem_hi);
	storeAppendPrintf(sentry, "\tswapout: %d bytes done, %d queued, FD %d\n",
	    (int) mem->swapout.done_offset,
	    (int) mem->swapout.queue_offset,
	    mem->swapout.fd);
	for (i = 0; i < mem->nclients; i++) {
	    sc = &mem->clients[i];
	    if (sc->callback_data == NULL)
		continue;
	    storeAppendPrintf(sentry, "\tClient #%d\n", i);
	    storeAppendPrintf(sentry, "\t\tcopy_offset: %d\n",
		(int) sc->copy_offset);
	    storeAppendPrintf(sentry, "\t\tseen_offset: %d\n",
		(int) sc->seen_offset);
	    storeAppendPrintf(sentry, "\t\tcopy_size: %d\n",
		(int) sc->copy_size);
	    storeAppendPrintf(sentry, "\t\tswapin_fd: %d\n",
		(int) sc->swapin_fd);
	}
	storeAppendPrintf(sentry, "\n");
	storeBufferFlush(sentry);
    }
}

