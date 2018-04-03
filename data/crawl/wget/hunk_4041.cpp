 	      if (tml >= tmr &&
 		  (hstat.contlen == -1 || local_size == hstat.contlen))
 		{
-		  logprintf (LOG_VERBOSE, _("\
-Local file `%s' is more recent, not retrieving.\n\n"), u->local);
+		  if (local_dot_orig_file_exists)
+		    /* We can't collapse this down into just one logprintf()
+		       call with a variable set to u->local or the .orig
+		       filename because we have to malloc() space for the
+		       latter, and because there are multiple returns above (a
+		       coding style no-no by many measures, for reasons such as
+		       this) we'd have to remember to free() the string at each
+		       one to avoid a memory leak. */
+		    logprintf (LOG_VERBOSE, _("\
+Server file no newer than local file `%s.orig' -- not retrieving.\n\n"),
+			       u->local);
+		  else
+		    logprintf (LOG_VERBOSE, _("\
+Server file no newer than local file `%s' -- not retrieving.\n\n"), u->local);
 		  FREEHSTAT (hstat);
 		  return RETROK;
 		}
 	      else if (tml >= tmr)
 		logprintf (LOG_VERBOSE, _("\
-The sizes do not match (local %ld), retrieving.\n"), local_size);
+The sizes do not match (local %ld) -- retrieving.\n"), local_size);
 	      else
 		logputs (LOG_VERBOSE,
 			 _("Remote file is newer, retrieving.\n"));
