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
