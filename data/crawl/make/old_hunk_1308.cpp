	  p = allocated_variable_expand (next_token (p + (noerror ? 8 : 7)));
	  if (*p == '\0')
	    {
	      makefile_error (filename, lineno,
			      "no file name for `%sinclude'",
			      noerror ? "-" : "");
	      continue;
