#endif
	    if (shutdown_pending) {
		normal_shutdown();
	    } else {
		fatal_dump("MAIN: SHUTDOWN from comm_select, but nothing pending.");
	    }
