	    }
	  if (err==FTPOK)
	    {
	      struct address_list *al;

	      sprintf (thost, "%d.%d.%d.%d",
		       pasv_addr[0], pasv_addr[1], pasv_addr[2], pasv_addr[3]);
	      tport = (pasv_addr[4] << 8) + pasv_addr[5];

	      al = lookup_host (thost, 0);
	      if (!al)
		{
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  return HOSTERR;
		}
	      dtsock = connect_to_many (al, tport, 0);
	      address_list_release (al);

	      if (dtsock < 0)
		{
		  int save_errno = errno;
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  return save_errno == ECONNREFUSED ? CONREFUSED : CONERROR;
		}

	      passive_mode_open= 1;  /* Flag to avoid accept port */
	      if (!opt.server_response)
		logputs (LOG_VERBOSE, _("done.    "));
