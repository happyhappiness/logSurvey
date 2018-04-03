  /* Disallow embedded newlines.  */
  if (strchr (val, '\n'))
    {
      fprintf (stderr, _("%s: %s: Invalid value %s.\n"),
               exec_name, com, quote (val));
      return false;
    }
  xfree_null (opt.useragent);
