       if (opt.verbose)
 	{
           if (!opt.server_response)
-	    logprintf (LOG_VERBOSE, "==> SIZE %s ... ", u->file);
+	    logprintf (LOG_VERBOSE, "==> SIZE %s ... ", escnonprint (u->file));
 	}
 
       err = ftp_size (csock, u->file, len);
