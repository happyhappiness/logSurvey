
	  if (!opt.server_response)
	    logprintf (LOG_VERBOSE, "==> CWD %s ... ", target);
	  err = ftp_cwd (&con->rbuf, target);
	  /* FTPRERR, WRITEFAILED, FTPNSFOD */
	  switch (err)
	    {
