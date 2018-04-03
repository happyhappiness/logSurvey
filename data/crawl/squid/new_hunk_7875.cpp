	     * errno indicates that the directory doesn't exist */
	    if (errno != ENOENT)
		continue;
	    debug(20,0, "WARNING: Cannot write to '%s' for storage swap area.\n", name);
	    debug(20,0, "Forcing a *full restart* (e.g., cached -z)...");
	    zap_disk_store = 1;
	    return;
	}
