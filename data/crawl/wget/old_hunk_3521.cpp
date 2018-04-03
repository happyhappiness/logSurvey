	    }
	  if (err==FTPOK)
	    {
	      sprintf (thost, "%d.%d.%d.%d",
		       pasv_addr[0], pasv_addr[1], pasv_addr[2], pasv_addr[3]);
	      tport = (pasv_addr[4] << 8) + pasv_addr[5];
	      DEBUGP ((_("Will try connecting to %s:%hu.\n"), thost, tport));
	      err = make_connection (&dtsock, thost, tport);
	      switch (err)
		{
		  /* Do not close the socket in first several cases,
		     since it wasn't created at all.  */
		case HOSTERR:
		  logputs (LOG_VERBOSE, "\n");
		  logprintf (LOG_NOTQUIET, "%s: %s\n", thost,
			     herrmsg (h_errno));
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  return HOSTERR;
		  break;
		case CONSOCKERR:
		  logputs (LOG_VERBOSE, "\n");
		  logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  return CONSOCKERR;
		  break;
		case CONREFUSED:
		  logputs (LOG_VERBOSE, "\n");
		  logprintf (LOG_NOTQUIET,
			     _("Connection to %s:%hu refused.\n"),
			     thost, tport);
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  closeport (dtsock);
		  return CONREFUSED;
		case CONERROR:
		  logputs (LOG_VERBOSE, "\n");
		  logprintf (LOG_NOTQUIET, "connect: %s\n",
			     strerror (errno));
		  CLOSE (csock);
		  rbuf_uninitialize (&con->rbuf);
		  closeport (dtsock);
		  return CONERROR;
		  break;
		default:
		  /* #### What?!  */
		  DO_NOTHING;
		}
	      passive_mode_open= 1;  /* Flag to avoid accept port */
	      if (!opt.server_response)
		logputs (LOG_VERBOSE, _("done.    "));
