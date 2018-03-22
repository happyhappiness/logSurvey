 	      ERROR ((0, errno, "%s:%ld: %s",
 		      quotearg_colon (listed_incremental_option), lineno,
 		      _("Invalid modification time (nanoseconds)")));
-	      nsec = -1;
+	      mtime.tv_nsec = -1;
 	    }
 	  else
-	    nsec = u;
-	  mtime.tv_sec = sec;
-	  mtime.tv_nsec = nsec;
+	    mtime.tv_nsec = u;
 	  strp = ebuf;
 	}
       else
-	memset (&mtime, 0, sizeof mtime);
+	mtime.tv_sec = mtime.tv_nsec = 0;
 
-      errno = 0;
-      u = strtoumax (strp, &ebuf, 10);
-      if (!errno && TYPE_MAXIMUM (dev_t) < u)
-	errno = ERANGE;
-      if (errno || strp == ebuf || *ebuf != ' ')
-	{
-	  ERROR ((0, errno, "%s:%ld: %s",
-		  quotearg_colon (listed_incremental_option), lineno,
-		  _("Invalid device number")));
-	  dev = (dev_t) -1;
-	}
-      else
-	dev = u;
+      dev = strtosysint (strp, &ebuf,
+			 TYPE_MINIMUM (dev_t), TYPE_MAXIMUM (dev_t));
       strp = ebuf;
+      if (errno || *strp != ' ')
+	ERROR ((0, errno, "%s:%ld: %s",
+		quotearg_colon (listed_incremental_option), lineno,
+		_("Invalid device number")));
 
-      errno = 0;
-      u = strtoumax (strp, &ebuf, 10);
-      if (!errno && TYPE_MAXIMUM (ino_t) < u)
-	errno = ERANGE;
-      if (errno || strp == ebuf || *ebuf != ' ')
-	{
-	  ERROR ((0, errno, "%s:%ld: %s",
-		  quotearg_colon (listed_incremental_option), lineno,
-		  _("Invalid inode number")));
-	  ino = (ino_t) -1;
-	}
-      else
-	ino = u;
+      ino = strtosysint (strp, &ebuf,
+			 TYPE_MINIMUM (ino_t), TYPE_MAXIMUM (ino_t));
       strp = ebuf;
+      if (errno || *strp != ' ')
+	ERROR ((0, errno, "%s:%ld: %s",
+		quotearg_colon (listed_incremental_option), lineno,
+		_("Invalid inode number")));
 
       strp++;
       unquote_string (strp);
