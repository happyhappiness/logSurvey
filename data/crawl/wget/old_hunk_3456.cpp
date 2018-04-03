    {
      if (opt.ftp_pasv > 0)
	{
	  if (!opt.server_response)
	    logputs (LOG_VERBOSE, "==> PASV ... ");
	  err = ftp_pasv (&con->rbuf, pasv_addr);
	  /* FTPRERR, WRITEFAILED, FTPNOPASV, FTPINVPASV */
	  switch (err)
	    {
