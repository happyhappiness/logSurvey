 	      ERROR((1, 0, _("Bad incremental file format")));
 
 	  incremental_version = (errno = 0, strtoumax (ebuf+1, &ebuf, 10));
-	  if (getline (&buf, &bufsize, fp) <= 0)
-	    {
-	      read_error (listed_incremental_option);
-	      free (buf);
-	      return;
-	    }
-	  ++lineno;
 	}
       else
 	incremental_version = 0;
 
-      if (incremental_version > TAR_INCREMENTAL_VERSION)
-	ERROR((1, 0, _("Unsupported incremental format version: %d"),
-	       incremental_version));
-
-      t = u = (errno = 0, strtoumax (buf, &ebuf, 10));
-      if (buf == ebuf || (u == 0 && errno == EINVAL))
-	ERROR ((0, 0, "%s:%ld: %s",
-		quotearg_colon (listed_incremental_option),
-		lineno,
-		_("Invalid time stamp")));
-      else if (t != u)
-	ERROR ((0, 0, "%s:%ld: %s",
-		quotearg_colon (listed_incremental_option),
-		lineno,
-		_("Time stamp out of range")));
-      else if (incremental_version == 1)
+      switch (incremental_version)
 	{
-	  newer_mtime_option.tv_sec = t;
-
-	  t = u = (errno = 0, strtoumax (buf, &ebuf, 10));
-	  if (buf == ebuf || (u == 0 && errno == EINVAL))
-	    ERROR ((0, 0, "%s:%ld: %s",
-		    quotearg_colon (listed_incremental_option),
-		    lineno,
-		    _("Invalid time stamp")));
-	  else if (t != u)
-	    ERROR ((0, 0, "%s:%ld: %s",
-		    quotearg_colon (listed_incremental_option),
-		    lineno,
-		    _("Time stamp out of range")));
-	  newer_mtime_option.tv_nsec = t;
-	}
-      else
-	{
-	  /* pre-1 incremental format does not contain nanoseconds */
-	  newer_mtime_option.tv_sec = t;
-	  newer_mtime_option.tv_nsec = 0;
-	}
-
-      while (0 < (n = getline (&buf, &bufsize, fp)))
-	{
-	  dev_t dev;
-	  ino_t ino;
-	  bool nfs = buf[0] == '+';
-	  char *strp = buf + nfs;
-	  struct timespec mtime;
-
-	  lineno++;
-
-	  if (buf[n - 1] == '\n')
-	    buf[n - 1] = '\0';
-
-	  if (incremental_version == 1)
-	    {
-	      errno = 0;
-	      mtime.tv_sec = u = strtoumax (strp, &ebuf, 10);
-	      if (!isspace (*ebuf))
-		ERROR ((0, 0, "%s:%ld: %s",
-			quotearg_colon (listed_incremental_option), lineno,
-			_("Invalid modification time (seconds)")));
-	      else if (mtime.tv_sec != u)
-		ERROR ((0, 0, "%s:%ld: %s",
-			quotearg_colon (listed_incremental_option), lineno,
-			_("Modification time (seconds) out of range")));
-	      strp = ebuf;
-
-	      errno = 0;
-	      mtime.tv_nsec = u = strtoumax (strp, &ebuf, 10);
-	      if (!isspace (*ebuf))
-		ERROR ((0, 0, "%s:%ld: %s",
-			quotearg_colon (listed_incremental_option), lineno,
-			_("Invalid modification time (nanoseconds)")));
-	      else if (mtime.tv_nsec != u)
-		ERROR ((0, 0, "%s:%ld: %s",
-			quotearg_colon (listed_incremental_option), lineno,
-			_("Modification time (nanoseconds) out of range")));
-	      strp = ebuf;
-	    }
-	  else
-	    memset (&mtime, 0, sizeof mtime);
-
-	  errno = 0;
-	  dev = u = strtoumax (strp, &ebuf, 10);
-	  if (!isspace (*ebuf))
-	    ERROR ((0, 0, "%s:%ld: %s",
-		    quotearg_colon (listed_incremental_option), lineno,
-		    _("Invalid device number")));
-	  else if (dev != u)
-	    ERROR ((0, 0, "%s:%ld: %s",
-		    quotearg_colon (listed_incremental_option), lineno,
-		    _("Device number out of range")));
-	  strp = ebuf;
-
-	  errno = 0;
-	  ino = u = strtoumax (strp, &ebuf, 10);
-	  if (!isspace (*ebuf))
-	    ERROR ((0, 0, "%s:%ld: %s",
-		    quotearg_colon (listed_incremental_option), lineno,
-		    _("Invalid inode number")));
-	  else if (ino != u)
-	    ERROR ((0, 0, "%s:%ld: %s",
-		    quotearg_colon (listed_incremental_option), lineno,
-		    _("Inode number out of range")));
-	  strp = ebuf;
+	case 0:
+	case 1:
+	  read_incr_db_01 (incremental_version, buf);
+	  break;
 
-	  strp++;
-	  unquote_string (strp);
-	  note_directory (strp, mtime, dev, ino, nfs, false);
+	case TAR_INCREMENTAL_VERSION:
+	  read_incr_db_2 ();
+	  break;
+	  
+	default:
+	  ERROR ((1, 0, _("Unsupported incremental format version: %d"),
+		  incremental_version));
 	}
+      
     }
 
-  if (ferror (fp))
+  if (ferror (listed_incremental_stream))
     read_error (listed_incremental_option);
   if (buf)
     free (buf);
