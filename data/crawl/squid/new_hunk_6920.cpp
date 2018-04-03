	    }
	    if (shutdown_pending) {
		normal_shutdown();
#if 0
	    } else if (reconfigure_pending) {
		mainReconfigure();
		reconfigure_pending = 0;	/* reset */
#endif
	    } else {
		fatal_dump("MAIN: SHUTDOWN from comm_select, but nothing pending.");
	    }