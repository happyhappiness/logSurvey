		(int) sc->copy_size);
	    storeAppendPrintf(s, "\t\tswapin_fd: %d\n",
		(int) sc->swapin_fd);
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
