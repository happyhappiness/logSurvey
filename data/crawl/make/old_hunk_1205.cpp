}


static char *
expand_builtin_function (o, argc, argv, entry_p)
     char *o;
     int argc;
     char **argv;
     struct function_table_entry *entry_p;
{
  int min = (entry_p->required_args > 0
             ? entry_p->required_args
             : -entry_p->required_args);

  if (argc < min)
    fatal (reading_file,
           "Insufficient number of arguments (%d) to function `%s'",
           argc, entry_p->name);

  if (!entry_p->func_ptr)
    fatal (reading_file, "Unimplemented on this platform: function `%s'",
           entry_p->name);

  return entry_p->func_ptr (o, argv, entry_p->name);
}

/* Check for a function invocation in *STRINGP.  *STRINGP points at the
   opening ( or { and is not null-terminated.  If a function invocation
   is found, expand it into the buffer at *OP, updating *OP, incrementing
   *STRINGP past the reference and returning nonzero.  If not, return zero.  */

int
handle_function (op, stringp)
     char **op;
     char **stringp;
{
  const struct function_table_entry *entry_p;
  char openparen = (*stringp)[0];
  char closeparen = openparen == '(' ? ')' : '}';
  char *beg = *stringp + 1;
  char *endref;
  int count = 0;
  char *argbeg;
  register char *p;
  char **argv, **argvp;
  int nargs;

  entry_p = lookup_function (function_table, beg);

  if (!entry_p)
    return 0;

  /* We have found a call to a builtin function.  Find the end of the
     arguments, and do the function.  */

  endref = beg + entry_p->len;

  /* Space after function name isn't part of the args.  */
  p = next_token (endref);
  argbeg = p;

  /* Find the end of the function invocation, counting nested use of
     whichever kind of parens we use.  Since we're looking, count commas
     to get a rough estimate of how many arguments we might have.  The
     count might be high, but it'll never be low.  */

  for (nargs=1; *p != '\0'; ++p)
    if (*p == ',')
      ++nargs;
    else if (*p == openparen)
      ++count;
    else if (*p == closeparen && --count < 0)
      break;

  if (count >= 0)
    fatal (reading_file,
	   "unterminated call to function `%s': missing `%c'",
	   entry_p->name, closeparen);

  /* Get some memory to store the arg pointers.  */
  argvp = argv = (char **) alloca (sizeof(char *) * (nargs + 2));

  /* Chop the string into arguments, then store the end pointer and a nul.
     If REQUIRED_ARGS is positive, as soon as we hit that many assume the
     rest of the string is part of the last argument.  */
  *argvp = argbeg;
  nargs = 1;
  while (entry_p->required_args > 0 && nargs < entry_p->required_args)
    {
      char *next = find_next_argument (openparen, closeparen, *argvp, p);

      if (!next)
	break;

      *(++argvp) = next+1;
      ++nargs;
    }

  *(++argvp) = p+1;
  *(++argvp) = 0;

  /* If we should expand, do it.  */
  if (entry_p->expand_args)
    {
      for (argvp=argv; argvp[1] != 0; ++argvp)
	*argvp = expand_argument (*argvp, argvp[1]-1);

      /* end pointer doesn't make sense for expanded stuff.  */
      *argvp = 0;
    }

  /* Finally!  Run the function...  */
  *op = expand_builtin_function (*op, nargs, argv, entry_p);

  /* If we allocated memory for the expanded args, free it again.  */
  if (entry_p->expand_args)
    for (argvp=argv; *argvp != 0; ++argvp)
      free (*argvp);

  *stringp = p;

  return 1;
}


/* Glob-expand LINE.  The returned pointer is
   only good until the next call to string_glob.  */

