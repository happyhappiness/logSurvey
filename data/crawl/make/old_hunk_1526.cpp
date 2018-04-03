pfatal_with_name (name)
     char *name;
{
  extern int errno, sys_nerr;
  extern char *sys_errlist[];

  if (errno < sys_nerr)
    fatal ("%s: %s", name, sys_errlist[errno]);
  else
    fatal ("%s: Unknown error %d", name, errno);

  /* NOTREACHED */
}
