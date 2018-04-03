    MemPools[type] = memPoolCreate(name, size);
}

static void
memStats(StoreEntry * sentry)
{
    storeBuffer(sentry);
    memReport(sentry);
    /* memStringStats(sentry); */
    storeBufferFlush(sentry);
}



/*
 * PUBLIC ROUTINES
 */

/* find appropriate pool and use it (pools always init buffer with 0s) */
void *
memAllocate(mem_type type)
