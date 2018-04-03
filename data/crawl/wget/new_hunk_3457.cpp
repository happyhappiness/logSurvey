	    default:
	      abort ();
	      break;
	    }	/* switch(err) */
	  if (err==FTPOK)
	    {
	      dtsock = connect_to_one (&passive_addr, passive_port, 1);
	      if (dtsock < 0)
		{
		  int save_errno = errno;
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  logprintf (LOG_VERBOSE, _("couldn't connect to %s:%hu: %s\n"),
			     pretty_print_address (&passive_addr), passive_port,
			     strerror (save_errno));
		  return save_errno == ECONNREFUSED ? CONREFUSED : CONERROR;
		}

	      pasv_mode_open = 1;  /* Flag to avoid accept port */
	      if (!opt.server_response)
		logputs (LOG_VERBOSE, _("done.    "));
	    } /* err==FTP_OK */
	}

      if (!pasv_mode_open)   /* Try to use a port command if PASV failed */
	{
	  if (!opt.server_response)
	    logputs (LOG_VERBOSE, "==> PORT ... ");
