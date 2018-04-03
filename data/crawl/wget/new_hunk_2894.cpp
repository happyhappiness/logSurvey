static int
cmd_spec_useragent (const char *com, const char *val, void *place_ignored)
{
  /* Disallow embedded newlines.  */
  if (strchr (val, '\n'))
    {
      fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"),
	       exec_name, com, val);
