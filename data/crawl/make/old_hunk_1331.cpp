      if (debug_flag && !noexist)
	{
	  print_spaces (depth);
	  if (d_mtime == (time_t) -1)
	    printf ("Dependency `%s' does not exist.\n", dep_name (d));
	  else
	    printf ("Dependency `%s' is %s than dependent `%s'.\n",
