	     * when next_cleaning has arrived */
	    /* garbage collection */
	    if (getCleanRate() > 0 && cached_curtime >= next_cleaning) {
		debug(0, 1, "Performing a garbage collection...\n");
		n = storePurgeOld();
		debug(0, 1, "Garbage collection done, %d objects removed\n", n);
		next_cleaning = cached_curtime + getCleanRate();
	    }
	    /* house keeping */
	    break;
	default:
	    debug(0, 0, "MAIN: Internal error -- this should never happen.\n");
	    break;
	}
    }
