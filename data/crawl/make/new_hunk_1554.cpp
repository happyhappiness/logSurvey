  expanded_name = allocated_variable_expand (name);
  free (name);

  if (expanded_name[0] == '\0')
    {
      if (filename == 0)
	fatal ("empty variable name");
      else
	makefile_fatal (filename, lineno, "empty variable name");
    }

  v = define_variable (expanded_name, strlen (expanded_name),
		       recursive ? p : variable_expand (p),
		       origin, recursive);
