  die (1);
}

#ifndef HAVE_STRERROR
char *
strerror (errnum)
     int errnum;
{
  extern int errno, sys_nerr;
  extern char *sys_errlist[];
  static char buf[] = "Unknown error 12345678901234567890";

  if (errno < sys_nerr)
    return sys_errlist[errnum];

  sprintf ("Unknown error %d", buf, errnum);
  return buf;
}
#endif

/* Print an error message from errno.  */

void
perror_with_name (str, name)
     char *str, *name;
{
  error ("%s%s: %s", str, name, strerror (errno));
}

/* Print an error message from errno and exit.  */
