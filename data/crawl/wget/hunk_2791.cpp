 	  if (!head)
 	    {
 	      logprintf (LOG_VERBOSE, _("Failed reading proxy response: %s\n"),
-			 strerror (errno));
+			 fd_errstr (sock));
 	      CLOSE_INVALIDATE (sock);
 	      return HERR;
 	    }
