}

static int
cmd_spec_progress (const char *com, const char *val, void *closure)
{
  if (!valid_progress_implementation_p (val))
    {
      fprintf (stderr, _("%s: %s: Invalid progress type `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  set_progress_implementation (val);
  return 1;
}

static int
cmd_spec_recursive (const char *com, const char *val, void *closure)
{
  if (!cmd_boolean (com, val, &opt.recursive))
