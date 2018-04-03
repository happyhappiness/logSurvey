  return 1;
}

/* Validate --prefer-family and set the choice.  Allowed values are
   "IPv4", "IPv6", and "none".  */

static int
cmd_spec_prefer_family (const char *com, const char *val, void *closure)
{
  if (0 == strcasecmp (val, "ipv4"))
    {
      opt.prefer_family = prefer_ipv4;
      return 1;
    }
  else if (0 == strcasecmp (val, "ipv6"))
    {
      opt.prefer_family = prefer_ipv6;
      return 1;
    }
  else if (0 == strcasecmp (val, "none"))
    {
      opt.prefer_family = prefer_none;
      return 1;
    }
  fprintf (stderr, _("%s: %s: Invalid preferred family `%s'.\n"),
	   exec_name, com, val);
  return 0;
}

/* Set progress.type to VAL, but verify that it's a valid progress
   implementation before that.  */

