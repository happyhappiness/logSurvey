 {
   union block *start;
   size_t bufsize;
-  int sparse_index = 0;
+  int sparses = 0;
   ssize_t count;
 
   while (*sizeleft > 0)
     {
       start = find_next_block ();
       memset (start->buffer, 0, BLOCKSIZE);
-      bufsize = sparsearray[sparse_index].numbytes;
-      if (!bufsize)
-	{
-	  /* We blew it, maybe.  */
-	  char buf1[UINTMAX_STRSIZE_BOUND];
-	  char buf2[UINTMAX_STRSIZE_BOUND];
-
-	  ERROR ((0, 0, _("Wrote %s of %s bytes to file %s"),
-		  STRINGIFY_BIGINT (fullsize - *sizeleft, buf1),
-		  STRINGIFY_BIGINT (fullsize, buf2), quote (name)));
-	  break;
-	}
+      bufsize = sparsearray[sparses].numbytes;
+      if (! bufsize)
+	abort ();
 
-      if (lseek (file, sparsearray[sparse_index++].offset, SEEK_SET) < 0)
+      if (lseek (file, sparsearray[sparses++].offset, SEEK_SET) < 0)
 	{
-	  char buf[UINTMAX_STRSIZE_BOUND];
-	  int e = errno;
-	  ERROR ((0, e, _("lseek error at byte %s in file %s"),
-		  STRINGIFY_BIGINT (sparsearray[sparse_index - 1].offset,
-				    buf),
-		  quote (name)));
+	  (ignore_failed_read_option ? seek_warn_details : seek_error_details)
+	    (name, sparsearray[sparses - 1].offset);
 	  break;
 	}
 
