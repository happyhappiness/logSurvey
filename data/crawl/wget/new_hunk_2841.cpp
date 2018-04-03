    {
      free_vec (opt.user_headers);
      opt.user_headers = NULL;
      return true;
    }

  if (!check_user_specified_header (val))
    {
      fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
	       exec_name, com, val);
      return false;
    }
  opt.user_headers = vec_append (opt.user_headers, val);
  return true;
}

static bool
cmd_spec_htmlify (const char *com, const char *val, void *place_ignored)
{
  int flag = cmd_boolean (com, val, &opt.htmlify);
  if (flag && !opt.htmlify)
    opt.remove_listing = false;
  return flag;
}

/* Set the "mirror" mode.  It means: recursive download, timestamping,
   no limit on max. recursion depth, and don't remove listings.  */

static bool
cmd_spec_mirror (const char *com, const char *val, void *place_ignored)
{
  int mirror;

  if (!cmd_boolean (com, val, &mirror))
    return false;
  if (mirror)
    {
      opt.recursive = true;
      if (!opt.no_dirstruct)
	opt.dirstruct = true;
      opt.timestamping = true;
      opt.reclevel = INFINITE_RECURSION;
      opt.remove_listing = false;
    }
  return true;
}

/* Validate --prefer-family and set the choice.  Allowed values are
   "IPv4", "IPv6", and "none".  */

static bool
cmd_spec_prefer_family (const char *com, const char *val, void *place_ignored)
{
  static const struct decode_item choices[] = {
