 	      logprintf (LOG_NOTQUIET, _("No such directory `%s'.\n\n"),
 			 u->dir);
 	      fd_close (csock);
+	      con->csock = -1;
 	      return err;
 	      break;
 	    case FTPOK:
