       else
 	{
 	  logprintf (LOG_NOTQUIET, _("Read error (%s) in headers.\n"),
-		     strerror (errno));
+		     fd_errstr (sock));
 	  CLOSE_INVALIDATE (sock);
 	  request_free (req);
 	  return HERR;
