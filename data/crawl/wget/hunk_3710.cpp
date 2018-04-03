 	  FREEHSTAT (hstat);
 	  return err;
 	  break;
-   case CONSSLERR:
+	case CONSSLERR:
 	  /* Another fatal error.  */
 	  logputs (LOG_VERBOSE, "\n");
 	  logprintf (LOG_NOTQUIET, _("Unable to establish SSL connection.\n"));
