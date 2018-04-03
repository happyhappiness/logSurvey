       if (opt.spider)
 	{
 	  logprintf (LOG_NOTQUIET, "%d %s\n\n", hstat.statcode, hstat.error);
-	  free(filename_plus_orig_suffix);  /* must precede every return! */
+	  xfree (filename_plus_orig_suffix); /* must precede every return! */
 	  return RETROK;
 	}
 
