    value = allocated_variable_expand (v->value);
  v->expanding = 0;

  return value;
}

/* Warn that NAME is an undefined variable.  */

#ifdef __GNUC__
__inline
#endif
static void
warn_undefined (name, length)
     char *name;
     unsigned int length;
{
  if (warn_undefined_variables_flag)
    error (reading_file,
           _("warning: undefined variable `%.*s'"), (int)length, name);
}

/* Expand a simple reference to variable NAME, which is LENGTH chars long.  */
