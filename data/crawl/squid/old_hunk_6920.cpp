	    }
	    if (shutdown_pending) {
		normal_shutdown();
	    } else if (reconfigure_pending) {
		mainReconfigure();
		reconfigure_pending = 0;	/* reset */
	    } else {
		fatal_dump("MAIN: SHUTDOWN from comm_select, but nothing pending.");
	    }