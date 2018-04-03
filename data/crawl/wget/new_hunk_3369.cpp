    1 - success
    0 - failure
   -1 - empty */

static int
parse_line (const char *line, char **com, char **val, int *comind)
{
  const char *p;
  const char *end = line + strlen (line);
  const char *cmdstart, *cmdend;
  const char *valstart, *valend;

  char *cmdcopy;
  int ind;

  /* Skip leading and trailing whitespace.  */
  while (*line && ISSPACE (*line))
    ++line;
  while (end > line && ISSPACE (end[-1]))
    --end;

  /* Skip empty lines and comments.  */
  if (!*line || *line == '#')
    return -1;

  p = line;

  cmdstart = p;
  while (p < end && (ISALPHA (*p) || *p == '_' || *p == '-'))
    ++p;
  cmdend = p;

  /* Skip '=', as well as any space before or after it. */
  while (p < end && ISSPACE (*p))
    ++p;
  if (p == end || *p != '=')
    return 0;
  ++p;
  while (p < end && ISSPACE (*p))
    ++p;

  valstart = p;
  valend   = end;

  /* The line now known to be syntactically correct.  Check whether
     the command is valid.  */
  BOUNDED_TO_ALLOCA (cmdstart, cmdend, cmdcopy);
  dehyphen (cmdcopy);
  ind = findcmd (cmdcopy);
  if (ind == -1)
    return 0;

  /* The command is valid.  Now fill in the values and report success
     to the caller.  */
  *comind = ind;
  *com = strdupdelim (cmdstart, cmdend);
  *val = strdupdelim (valstart, valend);
  return 1;
}

/* Run commands[comind].action. */

static int
setval_internal (int comind, const char *com, const char *val)
{
  assert (0 <= comind && comind < countof (commands));
  return ((*commands[comind].action) (com, val, commands[comind].closure));
}

/* Run command COM with value VAL.  If running the command produces an
   error, report the error and exit.

   This is intended to be called from main() with commands not
   provided by the user, therefore it aborts when an unknown command
   is encountered.  Once the COMIND's are exported to init.h, this
   function will be changed to accept COMIND directly.  */

void
setoptval (const char *com, const char *val)
{
  int comind = findcmd (com);
  assert (comind != -1);
  if (!setval_internal (comind, com, val))
    exit (2);
}

void
run_command (const char *opt)
{
  char *com, *val;
  int comind;
  int status = parse_line (opt, &com, &val, &comind);
  if (status == 1)
    {
      if (!setval_internal (comind, com, val))
	exit (2);
      xfree (com);
      xfree (val);
    }
  else if (status == 0)
    {
      fprintf (stderr, "Invalid command `%s'\n", opt);
      exit (2);
    }
}

/* Generic helper functions, for use with `commands'. */
