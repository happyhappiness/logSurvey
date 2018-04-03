
    debug(18, 5) ("stat_init: Initializing...\n");
    obj = xcalloc(1, sizeof(cacheinfo));
    if (logfilename) {
	memset(LogfileName, '\0', SQUID_MAXPATHLEN);
	xstrncpy(LogfileName, logfilename, SQUID_MAXPATHLEN);
	LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT, NULL, NULL);
	if (LogfileFD == DISK_ERROR) {
	    debug(50, 0) ("%s: %s\n", LogfileName, xstrerror());
	    fatal("Cannot open logfile.");
	}
    }
    obj->log_append = log_append;
    obj->proto_id = urlParseProtocol;
    obj->proto_newobject = proto_newobject;
    obj->proto_purgeobject = proto_purgeobject;
