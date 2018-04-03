 	  logputs (LOG_NOTQUIET,
 		   _("Write failed, closing control connection.\n"));
 	  CLOSE (csock);
-	  closeport (dtsock);
+	  CLOSE (dtsock);
+	  CLOSE (local_sock);
 	  rbuf_uninitialize (&con->rbuf);
 	  return err;
 	  break;
 	case FTPNSFOD:
 	  logputs (LOG_VERBOSE, "\n");
 	  logprintf (LOG_NOTQUIET, _("No such file `%s'.\n\n"), u->file);
-	  closeport (dtsock);
+	  CLOSE (dtsock);
+	  CLOSE (local_sock);
 	  return err;
 	  break;
 	case FTPOK:
