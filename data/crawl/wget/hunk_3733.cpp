 	  logputs (LOG_VERBOSE, tmpstr);
 	  print_percentage (nrow * line_bytes + ndot * opt.dot_bytes + offs,
 			    expected);
+	  logprintf (LOG_VERBOSE, " @%s",
+		     rate (ndot * opt.dot_bytes + offs - initial_skip,
+			   time_offset, 1));
 	}
       logputs (LOG_VERBOSE, "\n\n");
       return 0;
