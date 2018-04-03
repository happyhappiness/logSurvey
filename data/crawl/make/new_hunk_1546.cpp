
  return value;
}

/* Expand a simple reference to variable NAME, which LENGTH chars long.  */

#ifdef __GNUC__
__inline
#endif
static char *
reference_variable (o, name, length)
     char *o;
     char *name;
     unsigned int length;
{
  register struct variable *v = lookup_variable (name, length);

  if (v != 0 && *v->value != '\0')
    {
      char *value = (v->recursive ? recursively_expand (v) : v->value);
      o = variable_buffer_output (o, value, strlen (value));
      if (v->recursive)
	free (value);
    }

  return o;
}

/* Scan LINE for variable references and expansion-function calls.
   Build in `variable_buffer' the result of expanding the references and calls.
