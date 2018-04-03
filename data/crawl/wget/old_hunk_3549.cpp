	logputs (LOG_VERBOSE, _("done.\n"));

      /* Fifth: Set the FTP type.  */
      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> TYPE %c ... ", TOUPPER (u->ftp_type));
      err = ftp_type (&con->rbuf, TOUPPER (u->ftp_type));
      /* FTPRERR, WRITEFAILED, FTPUNKNOWNTYPE */
      switch (err)
	{
