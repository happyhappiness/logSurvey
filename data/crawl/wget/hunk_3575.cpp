 		  logprintf (LOG_VERBOSE, _("\
 Server file no newer than local file `%s' -- not retrieving.\n\n"),
 			     local_filename);
-		  FREEHSTAT (hstat);
+		  free_hstat (&hstat);
+		  FREE_MAYBE (dummy);
 		  return RETROK;
 		}
 	      else if (tml >= tmr)
