		    path, xstrerror());
		fatal(tmpbuf);
	    }
	    debug(1, "storeInit: Created swap directory %s\n", path);
	    directory_created = 1;
	}
	if (zap_disk_store) {
	    debug(1, "storeInit: Zapping all objects on disk storage.\n");
	    /* This could be dangerous, second copy of cache can destroy the existing
	     * swap files of the previous cache. We may use rc file do it. */
	    tmpbuf[0] = '\0';
	    sprintf(tmpbuf, "cd %s; rm -rf log [0-9][0-9]", path);
	    debug(1, "storeInit: Running '%s'\n", tmpbuf);
	    system(tmpbuf);
	}
    }
