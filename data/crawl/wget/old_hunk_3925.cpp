      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> PWD ... ");
      err = ftp_pwd(&con->rbuf, &pwd);
      pwd_len = strlen(pwd);
      /* FTPRERR */
      switch (err)
      {
