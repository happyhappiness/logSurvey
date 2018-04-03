  else
    fprintf (stderr, "%s[%u]: *** ", program, makelevel);

  va_start (args, fmt);
  vfprintf (stderr, fmt, args);
  va_end (args);

  fputs (_(".  Stop.\n"), stderr);

