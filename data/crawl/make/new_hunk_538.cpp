  return o;
}

#ifdef HAVE_GUILE
static char *
func_guile (char *o, char **argv, const char *funcname UNUSED)
{
  if (argv[0] && argv[0][0] != '\0')
    {
      char *str = guile_eval_string (argv[0]);
      o = variable_buffer_output (o, str, strlen (str));
      free (str);
    }

  return o;
}
#endif

/* Lookup table for builtin functions.

   This doesn't have to be sorted; we use a straight lookup.  We might gain
