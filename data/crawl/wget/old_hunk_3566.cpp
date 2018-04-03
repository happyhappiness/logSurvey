	case CONREFUSED:
	  logputs (LOG_VERBOSE, "\n");
	  logprintf (LOG_NOTQUIET,
		     _("Connection to %s:%hu refused.\n"), u->host, u->port);
	  CLOSE (sock);
	  return CONREFUSED;
	case CONERROR:
