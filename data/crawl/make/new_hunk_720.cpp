  return o;
}

static char *
func_flavor (char *o, char **argv, const char *funcname UNUSED)
{
  register struct variable *v = lookup_variable (argv[0], strlen (argv[0]));

  if (v == 0)
    o = variable_buffer_output (o, "undefined", 9);
  else
    if (v->recursive)
      o = variable_buffer_output (o, "recursive", 9);
    else
      o = variable_buffer_output (o, "simple", 6);

  return o;
}

#ifdef VMS
# define IS_PATHSEP(c) ((c) == ']')
#else
