 	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
 	  CLOSE (csock);
 	  rbuf_uninitialize (&con->rbuf);
-	  closeport (dtsock);
+	  CLOSE (dtsock);
+	  CLOSE (local_sock);
 	  return FOPENERR;
 	}
     }
