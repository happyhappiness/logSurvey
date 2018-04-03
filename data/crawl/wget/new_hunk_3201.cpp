	      logprintf (LOG_NOTQUIET, _("No such directory `%s'.\n\n"),
			 u->dir);
	      fd_close (csock);
	      return err;
	      break;
	    case FTPOK:
