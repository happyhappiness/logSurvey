  char *value;

  if (v->expanding)
    {
      /* Expanding V causes infinite recursion.  Lose.  */
      if (reading_filename == 0)
	fatal ("Recursive variable `%s' references itself (eventually)",
	       v->name);
      else
	makefile_fatal
	  (reading_filename, *reading_lineno_ptr,
	   "Recursive variable `%s' references itself (eventually)",
	   v->name);
    }

  v->expanding = 1;
  value = allocated_variable_expand (v->value);
