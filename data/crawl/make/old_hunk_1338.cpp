  expanded_name = allocated_variable_expand (name);

  if (expanded_name[0] == '\0')
    makefile_fatal (filename, lineno, "empty variable name");

  /* Calculate the variable's new value in VALUE.  */

