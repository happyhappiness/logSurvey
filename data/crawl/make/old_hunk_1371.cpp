  expanded_name = allocated_variable_expand (name);

  if (expanded_name[0] == '\0')
    {
      if (filename == 0)
	fatal ("empty variable name");
      else
	makefile_fatal (filename, lineno, "empty variable name");
    }

  /* Calculate the variable's new value in VALUE.  */

  switch (flavor)
    {
    case bogus:
      /* Should not be possible.  */
      abort ();
      return 0;
    case simple:
      /* A simple variable definition "var := value".  Expand the value.  */
      value = variable_expand (p);
      break;
    case recursive:
      /* A recursive variable definition "var = value".
	 The value is used verbatim.  */
      value = p;
      break;
    case append:
      /* An appending variable definition "var += value".
	 Extract the old value and append the new one.  */
      v = lookup_variable (expanded_name, strlen (expanded_name));
