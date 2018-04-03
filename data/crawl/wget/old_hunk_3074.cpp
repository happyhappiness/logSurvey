  if (restval && (cmd & DO_RETR))
    {
      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> REST %ld ... ", restval);
      err = ftp_rest (csock, restval);

      /* FTPRERR, WRITEFAILED, FTPRESTFAIL */
