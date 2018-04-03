  expanded_name = allocated_variable_expand (name);
  free (name);

  v = define_variable (expanded_name, strlen (expanded_name),
		       recursive ? p : variable_expand (p),
		       origin, recursive);
