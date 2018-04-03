 		     tms, hstat.statcode, hstat.error);
 	  logputs (LOG_VERBOSE, "\n");
 	  FREEHSTAT (hstat);
+	  free(filename_plus_orig_suffix);  /* must precede every return! */
 	  return WRONGCODE;
 	}
 
