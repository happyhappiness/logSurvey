 	      logprintf (LOG_NOTQUIET, _("No such directory `%s'.\n\n"),
 			 u->dir);
 	      fd_close (csock);
-	      rbuf_uninitialize (&con->rbuf);
 	      return err;
 	      break;
 	    case FTPOK:
