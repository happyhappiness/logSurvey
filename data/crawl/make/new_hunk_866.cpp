  return result;
}

/* Given a variable, a value, and a flavor, define the variable.
   See the try_variable_definition() function for details on the parameters. */

struct variable *
do_variable_definition (flocp, varname, value, origin, flavor, target_var)
     const struct floc *flocp;
     const char *varname;
     char *value;
     enum variable_origin origin;
     enum variable_flavor flavor;
     int target_var;
{
  char *p, *alloc_value = NULL;
  struct variable *v;
  int append = 0;

  /* Calculate the variable's new value in VALUE.  */

  switch (flavor)
    {
    default:
    case f_bogus:
      /* Should not be possible.  */
      abort ();
