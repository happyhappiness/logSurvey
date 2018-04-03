	  logputs (LOG_NOTQUIET,
		   _("Write failed, closing control connection.\n"));
	  fd_close (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	  break;
	case FTPUNKNOWNTYPE:
