{
  if (warn_undefined_variables_flag)
    error (reading_file,
           _("warning: undefined variable `%.*s'"), (int)length, name);
}

/* Expand a simple reference to variable NAME, which is LENGTH chars long.  */
