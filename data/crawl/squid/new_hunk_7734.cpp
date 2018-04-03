		fatal_dump("Select Loop failed!");
	    break;
	case COMM_TIMEOUT:
	    if (getCleanRate() > 0 && squid_curtime >= next_cleaning) {
		debug(1, 1, "Performing a garbage collection...\n");
		n = storePurgeOld();
