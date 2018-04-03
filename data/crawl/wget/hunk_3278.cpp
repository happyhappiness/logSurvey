       if (!fp)
 	{
 	  logprintf (LOG_NOTQUIET, "%s: %s\n", con->target, strerror (errno));
-	  CLOSE (csock);
+	  xclose (csock);
 	  rbuf_uninitialize (&con->rbuf);
-	  CLOSE (dtsock);
-	  CLOSE (local_sock);
+	  xclose (dtsock);
+	  xclose (local_sock);
 	  return FOPENERR;
 	}
     }
