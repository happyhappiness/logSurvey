    1 - success
    0 - failure
   -1 - empty */
int
parse_line (const char *line, char **com, char **val)
{
  const char *p = line;
  const char *orig_comptr, *end;
  char *new_comptr;

  /* Skip whitespace.  */
  while (*p && ISSPACE (*p))
    ++p;

  /* Don't process empty lines.  */
  if (!*p || *p == '#')
    return -1;

  for (orig_comptr = p; ISALPHA (*p) || *p == '_' || *p == '-'; p++)
    ;
  /* The next char should be space or '='.  */
  if (!ISSPACE (*p) && (*p != '='))
    return 0;
  /* Here we cannot use strdupdelim() as we normally would because we
     want to skip the `-' and `_' characters in the input string.  */
  *com = (char *)xmalloc (p - orig_comptr + 1);
  for (new_comptr = *com; orig_comptr < p; orig_comptr++)
    {
      if (*orig_comptr == '_' || *orig_comptr == '-')
	continue;
      *new_comptr++ = *orig_comptr;
    }
  *new_comptr = '\0';
  /* If the command is invalid, exit now.  */
  if (comind (*com) == -1)
    {
      xfree (*com);
      return 0;
    }

  /* Skip spaces before '='.  */
  for (; ISSPACE (*p); p++);
  /* If '=' not found, bail out.  */
  if (*p != '=')
    {
      xfree (*com);
      return 0;
    }
  /* Skip spaces after '='.  */
  for (++p; ISSPACE (*p); p++);
  /* Get the ending position for VAL by starting with the end of the
     line and skipping whitespace.  */
  end = line + strlen (line) - 1;
  while (end > p && ISSPACE (*end))
    --end;
  *val = strdupdelim (p, end + 1);
  return 1;
}

/* Set COM to VAL.  This is the meat behind processing `.wgetrc'.  No
   fatals -- error signal prints a warning and resets to default
   value.  All error messages are printed to stderr, *not* to
   opt.lfile, since opt.lfile wasn't even generated yet.  */
int
setval (const char *com, const char *val)
{
  int ind;

  if (!com || !val)
    return 0;
  ind = comind (com);
  if (ind == -1)
    {
      /* #### Should I just abort()?  */
#ifdef DEBUG
      fprintf (stderr, _("%s: BUG: unknown command `%s', value `%s'.\n"),
	       exec_name, com, val);
#endif
      return 0;
    }
  return ((*commands[ind].action) (com, val, commands[ind].closure));
}

/* Generic helper functions, for use with `commands'. */
