	/* If this sanity check fails, we should just ... */
	fatal_dump(NULL);
    }
    e->lastref = cached_curtime;

    /* StoreLockObject() is called during icp_hit_or_miss and once by storeAbort 
     * If the object is NOT_IN_MEMORY, fault it in. */
