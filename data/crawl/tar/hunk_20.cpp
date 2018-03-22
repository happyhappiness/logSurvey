 
       if (version == 1)
 	{
-	  errno = 0;
-	  u = strtoumax (strp, &ebuf, 10);
-	  if (!errno && TYPE_MAXIMUM (time_t) < u)
-	    errno = ERANGE;
-	  if (errno || strp == ebuf || *ebuf != ' ')
-	    {
-	      ERROR ((0, errno, "%s:%ld: %s",
-		      quotearg_colon (listed_incremental_option), lineno,
-		      _("Invalid modification time (seconds)")));
-	      sec = (time_t) -1;
-	    }
-	  else
-	    sec = u;
+	  mtime = decode_timespec (strp, &ebuf, false);
 	  strp = ebuf;
+	  if (!valid_timespec (mtime) || *strp != ' ')
+	    ERROR ((0, errno, "%s:%ld: %s",
+		    quotearg_colon (listed_incremental_option), lineno,
+		    _("Invalid modification time")));
 
 	  errno = 0;
 	  u = strtoumax (strp, &ebuf, 10);
