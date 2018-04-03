	storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) mem->inmem_hi);
	storeAppendPrintf(s, "\tswapout: %d bytes queued\n",
	    (int) mem->swapout.queue_offset);
	if (mem->swapout.sio.getRaw())
	    storeAppendPrintf(s, "\tswapout: %d bytes written\n",
		(int) mem->swapout.sio->offset());
	for (i = 0, node = mem->clients.head; node; node = node->next, i++)
	    storeClientDumpStats((store_client *)node->data, s, i);
    }
