	     * when next_cleaning has arrived */
	    /* garbage collection */
	    if (getCleanRate() > 0 && cached_curtime >= next_cleaning) {
		debug(1, 1, "Performing a garbage collection...\n");
		n = storePurgeOld();
		debug(1, 1, "Garbage collection done, %d objects removed\n", n);
		next_cleaning = cached_curtime + getCleanRate();
	    }
	    /* house keeping */
	    break;
	default:
	    fatal_dump("MAIN: Internal error -- this should never happen.\n");
	    break;
	}
    }
