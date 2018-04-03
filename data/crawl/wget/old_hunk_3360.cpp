{
  int lockable_boolean_value;

  /*
   * If a config file said "always" or "never", don't allow command line
   * arguments to override the config file.
   */
  if (*(int *)closure == -1 || *(int *)closure == 2)
    return 1;

  if (!strcasecmp (val, "always") || !strcmp (val, "2"))
    lockable_boolean_value = 2;
  else if (!strcasecmp (val, "on")
	   || !strcasecmp (val, "yes")
	   || !strcmp (val, "1"))
    lockable_boolean_value = 1;
  else if (!strcasecmp (val, "off")
	   || !strcasecmp (val, "no")
	   || !strcmp (val, "0"))
    lockable_boolean_value = 0;
  else if (!strcasecmp (val, "never") || !strcmp (val, "-1"))
    lockable_boolean_value = -1;
  else
    {
      fprintf (stderr, _("%s: %s: Please specify always, on, off, "
			 "or never.\n"),
	       exec_name, com);
      return 0;
    }

