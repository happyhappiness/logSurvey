  return o;
}
#endif


#define STRING_SIZE_TUPLE(_s) (_s), (sizeof(_s)-1)

/* Lookup table for builtin functions.

   This doesn't have to be sorted; we use a straight lookup.  We might gain
   some efficiency by moving most often used functions to the start of the
   table.

   If REQUIRED_ARGS is positive, the function takes exactly that many
   arguments.  All subsequent text is included with the last argument.  So,
   since $(sort a,b,c) takes only one argument, it will be the full string
   "a,b,c".  If the value is negative, it's the minimum number of arguments.
   A function can have more, but if it has less an error is generated.

   EXPAND_ARGS means that all arguments should be expanded before invocation.
   Functions that do namespace tricks (foreach) don't automatically expand.  */

static char *func_call PARAMS((char *o, char **argv, const char *funcname));


static struct function_table_entry function_table[] =
{
 /* Name/size */                    /* ARG EXP? Function */
  { STRING_SIZE_TUPLE("addprefix"),     2,  1,  func_addsuffix_addprefix},
  { STRING_SIZE_TUPLE("addsuffix"),     2,  1,  func_addsuffix_addprefix},
  { STRING_SIZE_TUPLE("basename"),      1,  1,  func_basename_dir},
  { STRING_SIZE_TUPLE("dir"),           1,  1,  func_basename_dir},
  { STRING_SIZE_TUPLE("notdir"),        1,  1,  func_notdir_suffix},
  { STRING_SIZE_TUPLE("subst"),         3,  1,  func_subst},
  { STRING_SIZE_TUPLE("suffix"),        1,  1,  func_notdir_suffix},
  { STRING_SIZE_TUPLE("filter"),        2,  1,  func_filter_filterout},
  { STRING_SIZE_TUPLE("filter-out"),    2,  1,  func_filter_filterout},
  { STRING_SIZE_TUPLE("findstring"),    2,  1,  func_findstring},
  { STRING_SIZE_TUPLE("firstword"),     1,  1,  func_firstword},
  { STRING_SIZE_TUPLE("join"),          2,  1,  func_join},
  { STRING_SIZE_TUPLE("patsubst"),      3,  1,  func_patsubst},
  { STRING_SIZE_TUPLE("shell"),         1,  1,  func_shell},
  { STRING_SIZE_TUPLE("sort"),          1,  1,  func_sort},
  { STRING_SIZE_TUPLE("strip"),         1,  1,  func_strip},
  { STRING_SIZE_TUPLE("wildcard"),      1,  1,  func_wildcard},
  { STRING_SIZE_TUPLE("word"),          2,  1,  func_word},
  { STRING_SIZE_TUPLE("wordlist"),      3,  1,  func_wordlist},
  { STRING_SIZE_TUPLE("words"),         1,  1,  func_words},
  { STRING_SIZE_TUPLE("origin"),        1,  1,  func_origin},
  { STRING_SIZE_TUPLE("foreach"),       3,  0,  func_foreach},
  { STRING_SIZE_TUPLE("call"),         -1,  1,  func_call},
  { STRING_SIZE_TUPLE("error"),         1,  1,  func_error},
  { STRING_SIZE_TUPLE("warning"),       1,  1,  func_error},
#ifdef EXPERIMENTAL
  { STRING_SIZE_TUPLE("eq"),            2,  1,  func_eq},
  { STRING_SIZE_TUPLE("if"),            3,  0,  func_if},
  { STRING_SIZE_TUPLE("not"),           1,  1,  func_not},
#endif
  { 0 }
};


/* These must come after the definition of function_table[].  */

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
  while (entry_p->required_args < 0 || nargs < entry_p->required_args)
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


/* User-defined functions.  Expand the first argument as either a builtin
   function or a make variable, in the context of the rest of the arguments
   assigned to $1, $2, ... $N.  $0 is the name of the function.  */

static char *
func_call (o, argv, funcname)
     char *o;
     char **argv;
