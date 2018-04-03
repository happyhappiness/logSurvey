 	  ndot = 0;
 	  ++nrow;
 	  if (expected)
-	    {
-	      print_percentage (nrow * line_bytes, expected);
-	      logprintf (LOG_VERBOSE, " @%s",
-			 rate (line_bytes - (initial_skip % line_bytes),
-			       time_offset, 1));
-	    }
+	    print_percentage (nrow * line_bytes, expected);
+	  logprintf (LOG_VERBOSE, " @%s",
+		     rate (line_bytes - (initial_skip % line_bytes),
+			   time_offset, 1));
 	  initial_skip = 0;
 	  logprintf (LOG_VERBOSE, "\n%5ldK", nrow * line_bytes / 1024);
 	}
