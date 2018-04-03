    }
  if (modified != expected_change)
    {
      if (expected_change == 1)
	printf ("Expected modification with path_simplify(\"%s\").\n",
		test);
      else
