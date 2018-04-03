	if (mem->swapout.sio)
	    storeAppendPrintf(s, "\tswapout: %d bytes written\n",
		(int) storeOffset(mem->swapout.sio));
	for (i = 0, node = mem->clients.head; node; node = node->next, i++)
	    storeClientDumpStats(node->data, s, i);
    }
    storeAppendPrintf(s, "\n");
}
