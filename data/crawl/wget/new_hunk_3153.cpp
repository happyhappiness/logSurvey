
      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> PWD ... ");
      err = ftp_pwd (csock, &con->id);
      /* FTPRERR */
      switch (err)
	{
