 	    logputs (LOG_VERBOSE,
 		     opt.ignore_length ? _("ignored") : _("unspecified"));
 	  if (type)
-	    logprintf (LOG_VERBOSE, " [%s]\n", type);
+	    logprintf (LOG_VERBOSE, " [%s]\n", escnonprint (type));
 	  else
 	    logputs (LOG_VERBOSE, "\n");
 	}
