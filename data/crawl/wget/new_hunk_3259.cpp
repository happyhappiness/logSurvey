	  logprintf (LOG_NOTQUIET,
		     _("Unknown type `%c', closing control connection.\n"),
		     type_char);
	  xclose (csock);
	  rbuf_uninitialize (&con->rbuf);
	  return err;
	case FTPOK: