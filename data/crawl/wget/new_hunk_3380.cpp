}

static int
cmd_spec_restrict_file_names (const char *com, const char *val, void *closure)
{
  /* The currently accepted values are `none', `unix', and
     `windows'.  */
  if (0 == strcasecmp (val, "none"))
    opt.restrict_file_names = restrict_none;
  else if (0 == strcasecmp (val, "unix"))
    opt.restrict_file_names = restrict_shell;
  else if (0 == strcasecmp (val, "windows"))
    opt.restrict_file_names = restrict_windows;
  else
    {
      fprintf (stderr, _("%s: %s: Invalid specification `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  return 1;
}

static int
cmd_spec_useragent (const char *com, const char *val, void *closure)
{
  /* Just check for empty string and newline, so we don't throw total
