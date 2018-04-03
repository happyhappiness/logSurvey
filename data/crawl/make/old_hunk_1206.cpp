  return o;
}
#endif

/* User-defined functions.  Expand the first argument as either a builtin
   function or a make variable, in the context of the rest of the arguments
   assigned to $1, $2, ... $N.  $0 is the name of the function.  */

char *
func_call (o, argv, funcname)
     char *o;
     char **argv;
