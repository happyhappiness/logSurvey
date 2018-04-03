    {
      fprintf (stderr, _("%s: %s: Invalid number `%s'.\n"),
	       exec_name, com, val);
      return 0;
    }
  return 1;
}

/* Similar to cmd_number(), only accepts `inf' as a synonym for 0.  */
static int
cmd_number_inf (const char *com, const char *val, void *place)
{
  if (!strcasecmp (val, "inf"))
    {
      *(int *)place = 0;
      return 1;
    }
  return cmd_number (com, val, place);
}

/* Copy (strdup) the string at COM to a new location and place a
   pointer to *PLACE.  */
static int
cmd_string (const char *com, const char *val, void *place)
{
  char **pstring = (char **)place;

  xfree_null (*pstring);
  *pstring = xstrdup (val);
  return 1;
}

#ifndef WINDOWS
