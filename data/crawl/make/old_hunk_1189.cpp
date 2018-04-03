  expanded_name = allocated_variable_expand (name);

  if (expanded_name[0] == '\0')
    fatal (flocp, "empty variable name");

  /* Calculate the variable's new value in VALUE.  */

