	    debug(18, 0, "Cannot open logfile: %s\n", obj->logfilename);
	    obj->logfile_status = LOG_DISABLE;
	}

    }
    /* at the moment, store one char to make a storage manager happy */
    storeAppendPrintf(sentry, " ");
