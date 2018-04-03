    {
      fprintf (stderr, _("%s: %s: Invalid number `%s'.\n"),
	       exec_name, com, val);
      return false;
    }
  return true;
}

/* Similar to cmd_number(), only accepts `inf' as a synonym for 0.  */
static bool
cmd_number_inf (const char *com, const char *val, void *place)
{
  if (!strcasecmp (val, "inf"))
    {
      *(int *) place = 0;
      return true;
    }
  return cmd_number (com, val, place);
}

/* Copy (strdup) the string at COM to a new location and place a
   pointer to *PLACE.  */
static bool
cmd_string (const char *com, const char *val, void *place)
{
  char **pstring = (char **)place;

  xfree_null (*pstring);
  *pstring = xstrdup (val);
  return true;
}

#ifndef WINDOWS
