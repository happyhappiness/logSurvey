	storeAppendPrintf(sentry, "\tinmem_lo: %d\n", (int) mem->inmem_lo);
	storeAppendPrintf(sentry, "\tinmem_hi: %d\n", (int) mem->inmem_hi);
	storeAppendPrintf(sentry, "\tswapout: %d bytes done, %d queued, FD %d\n",
	    mem->swapout.done_offset,
	    mem->swapout.queue_offset,
	    mem->swapout.fd);
	for (i = 0; i < mem->nclients; i++) {
	    sc = &mem->clients[i];
