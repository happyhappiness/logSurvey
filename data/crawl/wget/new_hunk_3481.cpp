    needs_flushing = 1;
}

struct logvprintf_state {
  char *bigmsg;
  int expected_size;
  int allocated;
};

/* Print a message to the log.  A copy of message will be saved to
   saved_log, for later reusal by log_dump().

   It is not possible to code this function in a "natural" way, using
   a loop, because of the braindeadness of the varargs API.
   Specifically, each call to vsnprintf() must be preceded by va_start
   and followed by va_end.  And this is possible only in the function
   that contains the `...' declaration.  The alternative would be to
   use va_copy, but that's not portable.  */

static int
logvprintf (struct logvprintf_state *state, const char *fmt, va_list args)
{
  char smallmsg[128];
  char *write_ptr = smallmsg;
  int available_size = sizeof (smallmsg);
  int numwritten;

  if (!save_log_p)
    {
      /* In the simple case just call vfprintf(), to avoid needless
         allocation and games with vsnprintf(). */
      vfprintf (logfp, fmt, args);
      goto flush;
    }

  if (state->allocated != 0)
    {
      write_ptr = state->bigmsg;
      available_size = state->allocated;
    }

  /* The GNU coding standards advise not to rely on the return value
     of sprintf().  However, vsnprintf() is a relatively new function
     missing from legacy systems.  Therefore I consider it safe to
     assume that its return value is meaningful.  On the systems where
     vsnprintf() is not available, we use the implementation from
     snprintf.c which does return the correct value.  */
  numwritten = vsnprintf (write_ptr, available_size, fmt, args);

  /* vsnprintf() will not step over the limit given by available_size.
     If it fails, it will return either -1 (POSIX?) or the number of
     characters that *would have* been written, if there had been
     enough room.  In the former case, we double the available_size
     and malloc() to get a larger buffer, and try again.  In the
     latter case, we use the returned information to build a buffer of
     the correct size.  */

  if (numwritten == -1)
    {
      /* Writing failed, and we don't know the needed size.  Try
	 again with doubled size. */
      int newsize = available_size << 1;
      state->bigmsg = xrealloc (state->bigmsg, newsize);
      state->allocated = newsize;
      return 0;
    }
  else if (numwritten >= available_size)
    {
      /* Writing failed, but we know exactly how much space we
	 need. */
      int newsize = numwritten + 1;
      state->bigmsg = xrealloc (state->bigmsg, newsize);
      state->allocated = newsize;
      return 0;
    }

  /* Writing succeeded. */
  saved_append (write_ptr);
  fputs (write_ptr, logfp);
  if (state->bigmsg)
    xfree (state->bigmsg);

 flush:
  if (flush_log_p)
    logflush ();
  else
    needs_flushing = 1;

  return 1;
}

/* Flush LOGFP.  Useful while flushing is disabled.  */
