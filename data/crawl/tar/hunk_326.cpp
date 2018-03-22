 
       while (bufsize > BLOCKSIZE)
 	{
-#if 0
-	  if (amount_read)
-	    {
-	      count = safe_read (file, start->buffer + amount_read,
-				 BLOCKSIZE - amount_read);
-	      bufsize -= BLOCKSIZE - amount_read;
-	      amount_read = 0;
-	      set_next_block_after (start);
-	      start = find_next_block ();
-	      memset (start->buffer, 0, BLOCKSIZE);
-	    }
-#endif
-	  /* Store the data.  */
-
 	  count = safe_read (file, start->buffer, BLOCKSIZE);
 	  if (count < 0)
 	    {
-	      char buf[UINTMAX_STRSIZE_BOUND];
-	      int e = errno;
-	      ERROR ((0, e,
-		      _("Read error at byte %s, reading %lu bytes, in file %s"),
-		      STRINGIFY_BIGINT (fullsize - *sizeleft, buf),
-		      (unsigned long) bufsize, quote (name)));
+	      (ignore_failed_read_option
+	       ? read_warn_details
+	       : read_error_details)
+		(name, fullsize - *sizeleft, bufsize);
 	      return 1;
 	    }
 	  bufsize -= count;
