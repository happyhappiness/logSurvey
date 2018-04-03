
	/* read from ipcache */
	if (fgets(request, REQ_SZ, stdin) == NULL) {
	    exit(1);
	}
	t = strrchr(request, '\n');