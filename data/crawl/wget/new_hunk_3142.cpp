static int
cmd_spec_header (const char *com, const char *val, void *closure)
{
  if (!check_user_specified_header (val))
    {
      fprintf (stderr, _("%s: %s: Invalid header `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  return cmd_vector (com, val, closure);
}

static int
