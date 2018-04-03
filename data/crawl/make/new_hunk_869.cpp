    value = allocated_variable_expand (v->value);
  v->expanding = 0;

  if (file)
    current_variable_set_list = save;

  return value;
}

/* Expand a simple reference to variable NAME, which is LENGTH chars long.  */
