 	    {
 	      if (restval)
 		logputs (LOG_VERBOSE, "\n");
-	      logprintf (LOG_VERBOSE, "==> RETR %s ... ", u->file);
+	      logprintf (LOG_VERBOSE, "==> RETR %s ... ", escnonprint (u->file));
 	    }
 	}
 
