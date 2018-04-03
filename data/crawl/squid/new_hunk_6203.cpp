	for (i = 0, sc = &mem->clients[i]; sc != NULL; sc = sc->next, i++) {
	    if (sc->callback_data == NULL)
		continue;
	    storeAppendPrintf(s, "\tClient #%d, %p\n", i, sc->callback_data);
	    storeAppendPrintf(s, "\t\tcopy_offset: %d\n",
		(int) sc->copy_offset);
	    storeAppendPrintf(s, "\t\tseen_offset: %d\n",
