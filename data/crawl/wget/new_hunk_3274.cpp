	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET,
		   _("Write failed, closing control connection.\n"));
	  xclose (csock);
	  xclose (dtsock);
	  xclose (local_sock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
	case FTPNSFOD:
	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET, _("No such file `%s'.\n\n"), u->file);
	  xclose (dtsock);
	  xclose (local_sock);
	  return err;
	  break;
	case FTPOK:
