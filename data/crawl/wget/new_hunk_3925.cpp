      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> PWD ... ");
      err = ftp_pwd(&con->rbuf, &pwd);
      /* FTPRERR */
      switch (err)
      {
