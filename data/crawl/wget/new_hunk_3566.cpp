	case CONREFUSED:
	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET,
		     _("Connection to %s:%hu refused.\n"), conn->host,
		     conn->port);
	  CLOSE (sock);
	  return CONREFUSED;
	case CONERROR:
