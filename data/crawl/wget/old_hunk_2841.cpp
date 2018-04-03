    {
      free_vec (opt.user_headers);
      opt.user_headers = NULL;
      return 1;
    }

  if (!check_user_specified_header (val))
    {
      fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  opt.user_headers = vec_append (opt.user_headers, val);
  return 1;
}

static int
cmd_spec_htmlify (const char *com, const char *val, void *place_ignored)
{
  int flag = cmd_boolean (com, val, &opt.htmlify);
  if (flag && !opt.htmlify)
    opt.remove_listing = 0;
  return flag;
}

/* Set the "mirror" mode.  It means: recursive download, timestamping,
   no limit on max. recursion depth, and don't remove listings.  */

static int
cmd_spec_mirror (const char *com, const char *val, void *place_ignored)
{
  int mirror;

  if (!cmd_boolean (com, val, &mirror))
    return 0;
  if (mirror)
    {
      opt.recursive = 1;
      if (!opt.no_dirstruct)
	opt.dirstruct = 1;
      opt.timestamping = 1;
      opt.reclevel = INFINITE_RECURSION;
      opt.remove_listing = 0;
    }
  return 1;
}

/* Validate --prefer-family and set the choice.  Allowed values are
   "IPv4", "IPv6", and "none".  */

static int
cmd_spec_prefer_family (const char *com, const char *val, void *place_ignored)
{
  static const struct decode_item choices[] = {
