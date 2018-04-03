    memDataInit(MEM_SWAPDIR, "SwapDir", sizeof(SwapDir), 0);
    memDataInit(MEM_USHORTLIST, "ushort_list", sizeof(ushortlist), 0);
    memDataInit(MEM_WORDLIST, "wordlist", sizeof(wordlist), 0);
    for (t = MEM_NONE + 1; t < MEM_MAX; t++) {
	m = &MemData[t];
	/*
	 * If you hit this assertion, then you forgot to add a
	 * memDataInit() line for type 't' above.
	 */
	assert(m->size);
    }
    cachemgrRegister("mem",
	"Memory Utilization",
	memStats, 0);
}

void
memFreeMemory(void)
{
    mem_type t;
    memData *m;
    void *p;
    for (t = MEM_NONE + 1; t < MEM_MAX; t++) {
	m = &MemData[t];
	while (!stackEmpty(&m->Stack)) {
	    p = stackPop(&m->Stack);
	    xfree(p);
	}
	xfree(m->Stack.base);
    }
}

static void
memStats(StoreEntry * sentry)
{
    mem_type t;
    memData *m;
    size_t in_use = 0;
    size_t not_in_use = 0;
    size_t allocated = 0;
    storeBuffer(sentry);
    storeAppendPrintf(sentry, "%25s %6s %15s %15s\n",
	"NAME",
	"SIZE",
	"NOT-USED",
	"ALLOCATED");
    for (t = MEM_NONE + 1; t < MEM_MAX; t++) {
	m = &MemData[t];
	if (m->n_allocated == 0)
	    continue;
	storeAppendPrintf(sentry, "%25.25s %6d %6d %5d KB  %6d %5d KB\n",
	    m->name,
	    m->size,
	    stackSize(&m->Stack),
	    m->size * stackSize(&m->Stack) >> 10,
	    m->n_allocated,
	    m->size * m->n_allocated >> 10);
	in_use += m->size * m->n_used;
	not_in_use += m->size * stackSize(&m->Stack);
	allocated += m->size * m->n_allocated;
    }
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "Total Memory In Use      %6d KB\n",
	(int) in_use >> 10);
    storeAppendPrintf(sentry, "Total Memory Not In Use  %6d KB\n",
	(int) not_in_use >> 10);
    storeAppendPrintf(sentry, "Total Memory Allocated   %6d KB\n",
	(int) allocated >> 10);
    storeBufferFlush(sentry);
}

int
memInUse(mem_type type)
{
    return MemData[type].n_used;
}

/* ick */
