    if (mem != NULL) {
	storeAppendPrintf(s, "\tinmem_lo: %d\n", (int) mem->inmem_lo);
	storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) mem->inmem_hi);
	storeAppendPrintf(s, "\tswapout: %d bytes done, %d queued, FD %d\n",
	    (int) mem->swapout.done_offset,
	    (int) mem->swapout.queue_offset,
	    mem->swapout.fd);
	for (i = 0, sc = &mem->clients[i]; sc != NULL; sc = sc->next, i++) {
	    if (sc->callback_data == NULL)
		continue;
