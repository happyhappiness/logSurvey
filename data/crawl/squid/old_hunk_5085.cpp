}

static void
statStoreEntry(StoreEntry * s, StoreEntry * e)
{
    MemObject *mem = e->mem_obj;
    storeAppendPrintf(s, "KEY %s\n", e->getMD5Text());
    storeAppendPrintf(s, "\t%s\n", describeStatuses(e));
    storeAppendPrintf(s, "\t%s\n", storeEntryFlags(e));
    storeAppendPrintf(s, "\t%s\n", describeTimestamps(e));
    storeAppendPrintf(s, "\t%d locks, %d clients, %d refs\n",
                      (int) e->lock_count,
                      storePendingNClients(e),
                      (int) e->refcount);
    storeAppendPrintf(s, "\tSwap Dir %d, File %#08X\n",
                      e->swap_dirn, e->swap_filen);

    if (mem != NULL)
        mem->stat (s);

    storeAppendPrintf(s, "\n");
}

/* process objects list */
