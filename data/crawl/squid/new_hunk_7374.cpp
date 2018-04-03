    if (logfilename) {
	memset(obj->logfilename, '0', SQUID_MAXPATHLEN);
	xstrncpy(obj->logfilename, logfilename, SQUID_MAXPATHLEN);
	obj->logfile_fd = file_open(obj->logfilename, NULL, O_WRONLY | O_CREAT, NULL, NULL);
	if (obj->logfile_fd == DISK_ERROR) {
	    debug(50, 0, "%s: %s\n", obj->logfilename, xstrerror());
	    fatal("Cannot open logfile.");
