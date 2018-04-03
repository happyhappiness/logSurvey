}


/* Return a formatted string buffer.
   LENGTH must be the maximum length of all format arguments, stringified.
   If we had a standard-compliant vsnprintf() this would be a lot simpler.
   Maybe in the future we'll include gnulib's version.  */

const char *
message_s (unsigned int length, int prefix, const char *fmt, ...)
{
  static char *buffer = NULL;
  static unsigned int bsize = 0;
  char *bp;
  va_list args;

  /* Compute the maximum buffer size we'll need, and make sure we have it.  */
  length += strlen (fmt) + strlen (program) + 4 + INTEGER_LENGTH + 2;
  if (length > bsize)
    {
      bsize = length * 2;
      buffer = xrealloc (buffer, bsize);
    }

  bp = buffer;
  if (prefix)
    {
      if (makelevel == 0)
        sprintf (bp, "%s: ", program);
      else
        sprintf (bp, "%s[%u]: ", program, makelevel);
      bp += strlen (buffer);
    }

  va_start (args, fmt);
  vsprintf (bp, fmt, args);
  va_end (args);

  return buffer;
}

/* Return a formatted error message in a buffer.
   LENGTH must be the maximum length of all format arguments, stringified.  */

const char *
error_s (unsigned int length, const gmk_floc *flocp, const char *fmt, ...)
{
  static char *buffer = NULL;
  static unsigned int bsize = 0;
  char *bp;
  va_list args;

  /* Compute the maximum buffer size we'll need, and make sure we have it.  */
  length += (strlen (fmt) + strlen (program) + 4 + INTEGER_LENGTH + 2
             + (flocp && flocp->filenm ? strlen (flocp->filenm) : 0));
  if (length > bsize)
    {
      bsize = length * 2;
      buffer = xrealloc (buffer, bsize);
    }

  bp = buffer;
  if (flocp && flocp->filenm)
    sprintf (bp, "%s:%lu: ", flocp->filenm, flocp->lineno);
  else if (makelevel == 0)
    sprintf (bp, "%s: ", program);
  else
    sprintf (bp, "%s[%u]: ", program, makelevel);
  bp += strlen (bp);

  va_start (args, fmt);
  vsprintf (bp, fmt, args);
  va_end (args);

  return buffer;
}

/* Print a message on stdout.  We could use message_s() to format it but then
   we'd need a va_list version...  */

void
message (int prefix, const char *fmt, ...)
{
  va_list args;

  log_working_directory (1, 0);

  if (fmt != 0)
    {
      if (prefix)
        {
          if (makelevel == 0)
            printf ("%s: ", program);
          else
            printf ("%s[%u]: ", program, makelevel);
        }
      va_start (args, fmt);
      vfprintf (stdout, fmt, args);
      va_end (args);
      putchar ('\n');
    }

  fflush (stdout);
}

/* Print an error message.  */

void
error (const gmk_floc *flocp, const char *fmt, ...)
{
  va_list args;

  log_working_directory (1, 0);

  if (flocp && flocp->filenm)
    fprintf (stderr, "%s:%lu: ", flocp->filenm, flocp->lineno);
  else if (makelevel == 0)
    fprintf (stderr, "%s: ", program);
  else
    fprintf (stderr, "%s[%u]: ", program, makelevel);

  va_start (args, fmt);
  vfprintf (stderr, fmt, args);
  va_end (args);

  putc ('\n', stderr);
  fflush (stderr);
}

/* Print an error message and exit.  */

void
fatal (const gmk_floc *flocp, const char *fmt, ...)
{
  va_list args;

  log_working_directory (1, 0);

  if (flocp && flocp->filenm)
    fprintf (stderr, "%s:%lu: *** ", flocp->filenm, flocp->lineno);
  else if (makelevel == 0)
    fprintf (stderr, "%s: *** ", program);
  else
    fprintf (stderr, "%s[%u]: *** ", program, makelevel);

  va_start (args, fmt);
  vfprintf (stderr, fmt, args);
  va_end (args);

  fputs (_(".  Stop.\n"), stderr);

  log_working_directory (0, 1);

  die (2);
}

#ifndef HAVE_STRERROR

#undef  strerror

char *
strerror (int errnum)
{
