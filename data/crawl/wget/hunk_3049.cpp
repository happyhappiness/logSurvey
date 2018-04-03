 	     no-buffering on opt.lfile.  */
 	  while ((line = read_whole_line (fp)))
 	    {
-	      logprintf (LOG_ALWAYS, "%s\n", line);
+	      logprintf (LOG_ALWAYS, "%s\n", escnonprint (line));
 	      xfree (line);
 	    }
 	  fclose (fp);
