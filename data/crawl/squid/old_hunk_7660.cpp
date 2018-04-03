
    debug(20, 3, "storeSwapOutHandle: '%s'\n", e->key);
    if (mem == NULL) {
	debug(20,0,"HELP! Someone is swapping out a bad entry:\n");
	debug(20,0,"%s\n", storeToString(e));
	storeRelease(e);
	return;
    }

    e->timestamp = squid_curtime;
    storeSwapFullPath(e->swap_file_number, filename);

