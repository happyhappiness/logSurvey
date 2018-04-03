	(int) e->lock_count,
	storePendingNClients(e),
	(int) e->refcount);
    storeAppendPrintf(s, "\tSwap File %#08X\n",
	e->swap_file_number);
    if (mem != NULL) {
	storeAppendPrintf(s, "\tinmem_lo: %d\n", (int) mem->inmem_lo);
	storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) mem->inmem_hi);
