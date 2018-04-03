}
#endif

/* User-defined functions.  Expand the first argument as either a builtin
   function or a make variable, in the context of the rest of the arguments
   assigned to $1, $2, ... $N.  $0 is the name of the function.  */

char *
func_apply (o, argv, funcname)
     char *o;
     char **argv;
     const char *funcname;
{
  char *fname;
  int flen;
  char *body;
  int i;
  const struct function_table_entry *entry_p;

  /* Applying nothing is a no-op.  */
  if (*argv[0] == '\0')
    return o;

  /* There is no way to define a variable with a space in the name, so strip
     trailing whitespace as a favor to the user.  */

  flen = strlen (argv[0]);
  fname = argv[0] + flen - 1;
  while (isspace (*fname))
    --fname;
  fname[1] = '\0';

  flen = fname - argv[0] + 1;
  fname = argv[0];

  /* Are we invoking a builtin function?  */

  entry_p = lookup_function (function_table, fname);

  if (entry_p)
    {
      for (i=0; argv[i+1]; ++i)
	;

      return expand_builtin_function (o, i, argv + 1, entry_p);
    }

  /* No, so the first argument is the name of a variable to be expanded and
     interpreted as a function.  Create the variable reference.  */
  body = alloca (flen + 4);
  body[0]='$';
  body[1]='(';
  strcpy (body + 2, fname);
  body[flen+2]=')';
  body[flen+3]= '\0';

  /* Set up arguments $(1) .. $(N).  $(0) is the function name.  */

  push_new_variable_scope ();

  for (i=0; *argv; ++i, ++argv)
    {
      char num[11];

      sprintf (num, "%d", i);
      define_variable (num, strlen (num), *argv, o_automatic, 0);
    }

  /* Expand the body in the context of the arguments, adding the result to
     the variable buffer.  */

  o = variable_expand_string (o, body, flen+3);

  pop_variable_scope ();

  return o + strlen(o);
}


#define STRING_SIZE_TUPLE(_s) (_s), (sizeof(_s)-1)

/* Lookup table for builtin functions.

