    {
      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> REST %ld ... ", restval);
      err = ftp_rest (&con->rbuf, restval);

      /* FTPRERR, WRITEFAILED, FTPRESTFAIL */
      switch (err)
