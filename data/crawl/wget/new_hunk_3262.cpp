	      logputs (LOG_VERBOSE, "\n");
	      logprintf (LOG_NOTQUIET, _("No such directory `%s'.\n\n"),
			 u->dir);
	      xclose (csock);
	      rbuf_uninitialize (&con->rbuf);
	      return err;
	      break;
