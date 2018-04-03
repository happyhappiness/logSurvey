  die (1);
}

/* Print an error message from errno.  */

void
perror_with_name (str, name)
     char *str, *name;
{
  extern int errno, sys_nerr;
  extern char *sys_errlist[];

  if (errno < sys_nerr)
    error ("%s%s: %s", str, name, sys_errlist[errno]);
  else
    error ("%s%s: Unknown error %d", str, name, errno);
}

/* Print an error message from errno and exit.  */
