	  exit (1);
	  break;
	}
      /* Third: Get the system type */
      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> SYST ... ");
      err = ftp_syst (&con->rbuf, &host_type);
      /* FTPRERR */
      switch (err)
	{
	case FTPRERR:
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("\
Error in server response, closing control connection.\n"));
	  CLOSE (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
	case FTPSRVERR:
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET,
		   _("Server error, can't determine system type.\n"));
	  break;
	case FTPOK:
	  /* Everything is OK.  */
	  break;
	default:
	  abort ();
	  break;
	}
      if (!opt.server_response)
	logputs (LOG_VERBOSE, _("done.    "));

      /* Fourth: Find the initial ftp directory */

      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> PWD ... ");
      err = ftp_pwd(&con->rbuf, &pwd);
      pwd_len = strlen(pwd);
      /* FTPRERR */
      switch (err)
      {
	case FTPRERR || FTPSRVERR :
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("\
Error in server response, closing control connection.\n"));
	  CLOSE (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
	case FTPOK:
	  /* Everything is OK.  */
	  break;
	default:
	  abort ();
	  break;
      }
      if (!opt.server_response)
	logputs (LOG_VERBOSE, _("done.\n"));

      /* Fifth: Set the FTP type.  */
      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> TYPE %c ... ", TOUPPER (u->ftp_type));
      err = ftp_type (&con->rbuf, TOUPPER (u->ftp_type));
