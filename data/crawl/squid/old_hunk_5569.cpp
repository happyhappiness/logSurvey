	if (mem->swapout.sio)
	    storeAppendPrintf(s, "\tswapout: %d bytes written\n",
		(int) storeOffset(mem->swapout.sio));
	for (i = 0, node = mem->clients.head; node; node = node->next, i++) {
	    sc = (store_client *) node->data;
	    if (sc->callback_data == NULL)
		continue;
	    storeAppendPrintf(s, "\tClient #%d, %p\n", i, sc->callback_data);
	    storeAppendPrintf(s, "\t\tcopy_offset: %d\n",
		(int) sc->copy_offset);
	    storeAppendPrintf(s, "\t\tcopy_size: %d\n",
		(int) sc->copy_size);
	    storeAppendPrintf(s, "\t\tflags:");
	    if (sc->flags.disk_io_pending)
		storeAppendPrintf(s, " disk_io_pending");
	    if (sc->flags.store_copying)
		storeAppendPrintf(s, " store_copying");
	    if (sc->flags.copy_event_pending)
		storeAppendPrintf(s, " copy_event_pending");
	    storeAppendPrintf(s, "\n");
	}
    }
    storeAppendPrintf(s, "\n");
}
