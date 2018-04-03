    check_winbindd();

    /* Main Loop */
    while (fgets (buf, BUFSIZE, stdin))
    {
	if (NULL == strchr(buf, '\n')) {
	    err = 1;
	    continue;
	}
	if (err) {
	    warn("Oversized message\n");
	    goto error;
	}
	
