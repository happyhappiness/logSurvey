
#include "squid.h"

/* module globals */

static MemPool *MemPools[MEM_MAX];

/* all pools share common memory chunks so it is probably better to ignore max_pages */
static void
memDataInit(mem_type type, const char *name, size_t size, int max_pages_notused)
{
    assert(name && size);
    MemPools[type] = memPoolCreate(name, size);
}

static void
memStats(StoreEntry * sentry)
{
    mem_type t;
    storeBuffer(sentry);
    storeAppendPrintf(sentry, "%-20s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",
	"Pool",	"Obj Size",
	"Capacity (#)", "Capacity (KB)", "Used (KB)", "HWater (KB)", 
	"Util (%)", "Grow Count",
	"Malloc (#)", "Malloc (KB)", "MHWater (KB)");
    for (t = MEM_NONE + 1; t < MEM_MAX; t++) {
	const MemPool *pool = MemPools[t];
	if (!memPoolWasNeverUsed(pool))
	    memPoolReport(pool, sentry);
    }
    storeAppendPrintf(sentry, "\n");
    /* memStringStats(sentry); */
    memReportTotals(sentry);
    storeBufferFlush(sentry);
}



/*
 * PUBLIC ROUTINES
 */

/* find appropriate pool and use it (pools always init buffer with 0s) */
void *
memAllocate(mem_type type)
{
    return memPoolAlloc(MemPools[type]);
}

/* find appropriate pool and use it */
void
memFree(mem_type type, void *p)
{
    memPoolFree(MemPools[type], p);
}

void
memInit(void)
{
    mem_type t;
    memInitModule();
    /* set all pointers to null */
    memset(MemPools, '\0', sizeof(MemPools));
    /*
     * it does not hurt much to have a lot of pools since sizeof(MemPool) is
     * small; someday we will figure out what to do with all the entries here
     * that are never used or used only once; perhaps we should simply use
     * malloc() for those? @?@
     */
    memDataInit(MEM_4K_BUF, "4K Buffer", 4096, 10);
    memDataInit(MEM_8K_BUF, "8K Buffer", 8192, 10);
    memDataInit(MEM_ACCESSLOGENTRY, "AccessLogEntry",
