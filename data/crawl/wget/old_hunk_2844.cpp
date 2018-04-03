    {
      fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  xfree_null (opt.useragent);
  opt.useragent = xstrdup (val);
  return 1;
}

/* Miscellaneous useful routines.  */

/* A very simple atoi clone, more useful than atoi because it works on
   delimited strings, and has error reportage.  Returns 1 on success,
   0 on failure.  If successful, stores result to *DEST.  */

static int
simple_atoi (const char *beg, const char *end, int *dest)
{
  int result = 0;
  int negative = 0;
  const char *p = beg;

  while (p < end && ISSPACE (*p))
