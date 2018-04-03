	  exit (1);
	  break;
	}
      /* Third: Set type to Image (binary).  */
      if (!opt.server_response)
	logprintf (LOG_VERBOSE, "==> TYPE %c ... ", TOUPPER (u->ftp_type));
      err = ftp_type (&con->rbuf, TOUPPER (u->ftp_type));
