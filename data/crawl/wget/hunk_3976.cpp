      the message needs to be stored with vsprintf().  However, Watcom
      C didn't like ARGS being used twice, so now we first vsprintf()
      the message, and then fwrite() it to LOGFP.  */
-  if (save_log_p && saved_log_size < SAVED_LOG_MAXSIZE)
+
+  if (!save_log_p)
     {
-      int len;
-      /* Increase size of `saved_log' exponentially.  */
-      DO_REALLOC (saved_log, saved_log_size,
-		  saved_log_offset + SAVED_LOG_MAXMSG, char);
-      /* Print the message to the log saver...  */
-      vsnprintf (saved_log + saved_log_offset, SAVED_LOG_MAXMSG, fmt, args);
-      /* ...and then dump it to LOGFP.  */
-      len = strlen (saved_log + saved_log_offset);
-      fwrite (saved_log + saved_log_offset, len, 1, logfp);
-      saved_log_offset += len;
-      /* If we ran off the limits and corrupted something, bail out
-	 immediately.  */
-      assert (saved_log_size >= saved_log_offset);
+      /* In the simple case just call vfprintf(), to avoid needless
+         allocation and games with vsnprintf(). */
+      vfprintf (logfp, fmt, args);
     }
   else
-    vfprintf (logfp, fmt, args);
+    {
+      char smallmsg[128];
+      char *bigmsg = NULL;
+      int available_size = sizeof (smallmsg);
+      char *write_ptr = smallmsg;
 
+      while (1)
+	{
+	  /* The GNU coding standards advise not to rely on the return
+             value of sprintf().  However, vsnprintf() is a relatively
+             new function missing from legacy systems.  Therefore it's
+             safe to assume that its return value is meaningful.  On
+             the systems where vsnprintf() is not available, we use
+             the implementation from snprintf.c which does return the
+             correct value.  */
+	  int numwritten = vsnprintf (write_ptr, available_size, fmt, args);
+
+	  /* vsnprintf() will not step over the limit given by
+             available_size.  If it fails, it will return either -1
+             (POSIX?) or the number of characters that *would have*
+             been written, if there had been enough room.  In the
+             former case, we double the available_size and malloc() to
+             get a larger buffer, and try again.  In the latter case,
+             we use the returned information to build a buffer of the
+             correct size.  */
+
+	  if (numwritten == -1)
+	    {
+	      /* Writing failed, and we don't know the needed size.
+		 Try again with doubled size. */
+	      available_size <<= 1;
+	      bigmsg = xrealloc (bigmsg, available_size);
+	      write_ptr = bigmsg;
+	    }
+	  else if (numwritten >= available_size)
+	    {
+	      /* Writing failed, but we know exactly how much space we
+		 need. */
+	      available_size = numwritten + 1;
+	      bigmsg = xrealloc (bigmsg, available_size);
+	      write_ptr = bigmsg;
+	    }
+	  else
+	    {
+	      /* Writing succeeded. */
+	      break;
+	    }
+	}
+      saved_append (write_ptr);
+      fputs (write_ptr, logfp);
+      if (bigmsg)
+	free (bigmsg);
+    }
   if (!opt.no_flush)
     fflush (logfp);
 }
