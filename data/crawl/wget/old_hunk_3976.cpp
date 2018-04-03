     the message needs to be stored with vsprintf().  However, Watcom
     C didn't like ARGS being used twice, so now we first vsprintf()
     the message, and then fwrite() it to LOGFP.  */
  if (save_log_p && saved_log_size < SAVED_LOG_MAXSIZE)
    {
      int len;
      /* Increase size of `saved_log' exponentially.  */
      DO_REALLOC (saved_log, saved_log_size,
		  saved_log_offset + SAVED_LOG_MAXMSG, char);
      /* Print the message to the log saver...  */
      vsnprintf (saved_log + saved_log_offset, SAVED_LOG_MAXMSG, fmt, args);
      /* ...and then dump it to LOGFP.  */
      len = strlen (saved_log + saved_log_offset);
      fwrite (saved_log + saved_log_offset, len, 1, logfp);
      saved_log_offset += len;
      /* If we ran off the limits and corrupted something, bail out
	 immediately.  */
      assert (saved_log_size >= saved_log_offset);
    }
  else
    vfprintf (logfp, fmt, args);

  if (!opt.no_flush)
    fflush (logfp);
}
