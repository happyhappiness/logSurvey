}

static void
statStoreEntry(MemBuf * mb, StoreEntry * e)
{
    MemObject *mem = e->mem_obj;
    memBufPrintf(mb, "KEY %s\n", e->getMD5Text());
    memBufPrintf(mb, "\t%s\n", describeStatuses(e));
    memBufPrintf(mb, "\t%s\n", storeEntryFlags(e));
    memBufPrintf(mb, "\t%s\n", describeTimestamps(e));
    memBufPrintf(mb, "\t%d locks, %d clients, %d refs\n",
                 (int) e->lock_count,
                 storePendingNClients(e),
                 (int) e->refcount);
    memBufPrintf(mb, "\tSwap Dir %d, File %#08X\n",
                 e->swap_dirn, e->swap_filen);

    if (mem != NULL)
        mem->stat (mb);

    memBufPrintf(mb, "\n");
}

/* process objects list */
