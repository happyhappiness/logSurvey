 	      logputs (LOG_NOTQUIET, _("\
 Error in server response, closing control connection.\n"));
 	      fd_close (csock);
+	      con->csock = -1;
 	      return err;
 	      break;
 	    case WRITEFAILED:
