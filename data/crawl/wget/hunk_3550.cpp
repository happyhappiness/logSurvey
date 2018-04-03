 	  logputs (LOG_VERBOSE, "\n");
 	  logprintf (LOG_NOTQUIET,
 		     _("Unknown type `%c', closing control connection.\n"),
-		     TOUPPER (u->ftp_type));
+		     type_char);
 	  CLOSE (csock);
 	  rbuf_uninitialize (&con->rbuf);
 	  return err;
