       if (!fp)
 	{
 	  logprintf (LOG_NOTQUIET, "%s: %s\n", u->local, strerror (errno));
-	  CLOSE (sock);
+	  CLOSE_FINISH (sock);
 	  FREE_MAYBE (all_headers);
 	  return FOPENERR;
 	}
