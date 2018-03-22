 		  count = safe_read (f, start->buffer, bufsize);
 		if (count < 0)
 		  {
-		    char buf[UINTMAX_STRSIZE_BOUND];
-		    int e = errno;
-		    ERROR ((0, e,
-			    _("Read error at byte %s, reading %lu bytes, in file %s"),
-			    STRINGIFY_BIGINT (current_stat.st_size - sizeleft,
-					      buf),
-			    (unsigned long) bufsize, quote (p)));
+		    (ignore_failed_read_option
+		     ? read_warn_details
+		     : read_error_details)
+		      (p, current_stat.st_size - sizeleft, bufsize);
 		    goto padit;
 		  }
 		sizeleft -= count;
