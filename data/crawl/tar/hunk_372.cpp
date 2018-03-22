 	  if (count < 0)
 	    {
 	      char buf[UINTMAX_STRSIZE_BOUND];
-	      ERROR ((0, errno,
+	      int e = errno;
+	      ERROR ((0, e,
 		      _("Read error at byte %s, reading %lu bytes, in file %s"),
 		      STRINGIFY_BIGINT (fullsize - *sizeleft, buf),
-		      (unsigned long) bufsize, name));
+		      (unsigned long) bufsize, quote (name)));
 	      return 1;
 	    }
 	  bufsize -= count;
