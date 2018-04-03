 	  if (hstat.contlen == -1)
 	    {
 	      logprintf (LOG_VERBOSE,
-			 _("%s (%s) - Read error at byte %ld (%s)."),
-			 tms, tmrate, hstat.len, strerror (errno));
+			 _("%s (%s) - Read error at byte %s (%s)."),
+			 tms, tmrate, number_to_static_string (hstat.len),
+			 strerror (errno));
 	      printwhat (count, opt.ntry);
 	      free_hstat (&hstat);
 	      continue;
