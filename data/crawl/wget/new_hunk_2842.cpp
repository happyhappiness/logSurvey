/* Set progress.type to VAL, but verify that it's a valid progress
   implementation before that.  */

static bool
cmd_spec_progress (const char *com, const char *val, void *place_ignored)
{
  if (!valid_progress_implementation_p (val))
    {
      fprintf (stderr, _("%s: %s: Invalid progress type `%s'.\n"),
	       exec_name, com, val);
      return false;
    }
  xfree_null (opt.progress_type);

  /* Don't call set_progress_implementation here.  It will be called
     in main() when it becomes clear what the log output is.  */
  opt.progress_type = xstrdup (val);
  return true;
}

/* Set opt.recursive to VAL as with cmd_boolean.  If opt.recursive is
   set to true, also set opt.dirstruct to true, unless opt.no_dirstruct
   is specified.  */

static bool
cmd_spec_recursive (const char *com, const char *val, void *place_ignored)
{
  if (!cmd_boolean (com, val, &opt.recursive))
    return false;
  else
    {
      if (opt.recursive && !opt.no_dirstruct)
	opt.dirstruct = true;
    }
  return true;
}

static bool
cmd_spec_restrict_file_names (const char *com, const char *val, void *place_ignored)
{
  int restrict_os = opt.restrict_files_os;
