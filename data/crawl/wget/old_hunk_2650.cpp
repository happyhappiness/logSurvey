{
  int restrict_os = opt.restrict_files_os;
  int restrict_ctrl = opt.restrict_files_ctrl;

  const char *end = strchr (val, ',');
  if (!end)
    end = val + strlen (val);

#define VAL_IS(string_literal) BOUNDED_EQUAL (val, end, string_literal)

  if (VAL_IS ("unix"))
    restrict_os = restrict_unix;
  else if (VAL_IS ("windows"))
    restrict_os = restrict_windows;
  else if (VAL_IS ("nocontrol"))
    restrict_ctrl = 0;
  else
    {
    err:
      fprintf (stderr,
	       _("%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"),
	       exec_name, com, val);
      return false;
    }

#undef VAL_IS

  if (*end)
    {
      if (!strcmp (end + 1, "nocontrol"))
	restrict_ctrl = false;
      else
	goto err;
    }

  opt.restrict_files_os = restrict_os;
  opt.restrict_files_ctrl = restrict_ctrl;
  return true;
}

