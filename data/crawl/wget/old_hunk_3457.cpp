	    default:
	      abort ();
	      break;
	    }
	  if (err==FTPOK)
	    {
	      unsigned short tport;

	      tport = (pasv_addr[4] << 8) + pasv_addr[5];
	      dtsock = connect_to_one (pasv_addr, tport, 1);

	      if (dtsock < 0)
		{
		  int save_errno = errno;
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  logprintf (LOG_VERBOSE, _("couldn't connect to %s:%hu: %s\n"),
			     pretty_print_address (pasv_addr), tport,
			     strerror (save_errno));
		  return save_errno == ECONNREFUSED ? CONREFUSED : CONERROR;
		}

	      passive_mode_open = 1;  /* Flag to avoid accept port */
	      if (!opt.server_response)
		logputs (LOG_VERBOSE, _("done.    "));
	    } /* err==FTP_OK */
	}

      if (!passive_mode_open)   /* Try to use a port command if PASV failed */
	{
	  if (!opt.server_response)
	    logputs (LOG_VERBOSE, "==> PORT ... ");
