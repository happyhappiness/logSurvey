    memDataInit(MEM_SWAPDIR, "SwapDir", sizeof(SwapDir), 0);
    memDataInit(MEM_USHORTLIST, "ushort_list", sizeof(ushortlist), 0);
    memDataInit(MEM_WORDLIST, "wordlist", sizeof(wordlist), 0);
    /* test that all entries are initialized */
    for (t = MEM_NONE + 1; t < MEM_MAX; t++) {
	/*
	 * If you hit this assertion, then you forgot to add a
	 * memDataInit() line for type 't' above.
	 */
	assert(MemPools[t]);
    }
    cachemgrRegister("mem",
	"Memory Utilization",
	memStats, 0);
}

void
memClean()
{
    mem_type t;
    int dirty_count = 0;
    for (t = MEM_NONE + 1; t < MEM_MAX; t++) {
	MemPool *pool = MemPools[t];
	if (memPoolIsUsedNow(pool)) {
	    memPoolDescribe(pool);
	    dirty_count++;
	}
    }
    if (dirty_count)
	debug(13, 2) ("memClean: %d pools are left dirty\n", dirty_count);
    else
	memCleanModule(); /* will free chunks and stuff */
}


int
memInUse(mem_type type)
{
    return memPoolUsedCount(MemPools[type]);
}

/* ick */
