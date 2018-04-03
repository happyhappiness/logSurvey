  if (strchr (val, '\n'))
    {
      fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"),
	       exec_name, com, val);
      return false;
    }
  xfree_null (opt.useragent);
