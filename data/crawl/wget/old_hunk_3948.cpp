	logputs (LOG_VERBOSE, _("==> CWD not needed.\n"));
      else
	{
	  /* Change working directory.  */
	  if (!opt.server_response)
	    logprintf (LOG_VERBOSE, "==> CWD %s ... ", u->dir);
	  err = ftp_cwd (&con->rbuf, u->dir);
	  /* FTPRERR, WRITEFAILED, FTPNSFOD */
	  switch (err)
	    {
