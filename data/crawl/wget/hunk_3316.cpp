 	  logputs (LOG_VERBOSE, "\n");
 	  logprintf (LOG_NOTQUIET, _("No such file or directory `%s'.\n\n"),
 		     ".");
-	  closeport (dtsock);
+	  CLOSE (dtsock);
+	  CLOSE (local_sock);
 	  return err;
 	  break;
 	case FTPOK:
