 		     file);
 	  if (unlink (file))
 	    logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
+	  logputs (LOG_VERBOSE, "\n");
 	  register_delete_file (file);
 	}
 
