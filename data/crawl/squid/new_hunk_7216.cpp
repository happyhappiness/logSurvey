	xstrncpy(obj->logfilename, logfilename, SQUID_MAXPATHLEN);
	obj->logfile_fd = file_open(obj->logfilename, O_WRONLY | O_CREAT, NULL, NULL);
	if (obj->logfile_fd == DISK_ERROR) {
	    debug(50, 0) ("%s: %s\n", obj->logfilename, xstrerror());
	    fatal("Cannot open logfile.");
	}
    }
