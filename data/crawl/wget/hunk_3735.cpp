       ++ndot;
       if (ndot == opt.dots_in_line)
 	{
+	  time_offset = elapsed_time () - last_timer;
+	  last_timer += time_offset;
+
 	  ndot = 0;
 	  ++nrow;
 	  if (expected)
-	    print_percentage (nrow * line_bytes, expected);
-	  logprintf (LOG_VERBOSE, "\n%5ldK ->", nrow * line_bytes / 1024);
+	    {
+	      print_percentage (nrow * line_bytes, expected);
+	      logprintf (LOG_VERBOSE, " @%s",
+			 rate (line_bytes - initial_skip, time_offset, 1));
+	    }
+	  initial_skip = 0;
+	  logprintf (LOG_VERBOSE, "\n%5ldK", nrow * line_bytes / 1024);
 	}
     }
   /* Reenable flushing.  */
