	    (int) mem->swapout.queue_offset);
	if (mem->swapout.sio)
	    storeAppendPrintf(s, "\tswapout: %d bytes written\n",
		(int) storeOffset(mem->swapout.sio));
	for (i = 0, sc = &mem->clients[i]; sc != NULL; sc = sc->next, i++) {
	    if (sc->callback_data == NULL)
		continue;
