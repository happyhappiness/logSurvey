  if (v->expanding)
    /* Expanding V causes infinite recursion.  Lose.  */
    fatal (reading_file,
           "Recursive variable `%s' references itself (eventually)", v->name);

  v->expanding = 1;
  value = allocated_variable_expand (v->value);
