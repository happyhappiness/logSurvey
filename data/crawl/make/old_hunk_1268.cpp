      /* Check the first argument.  */
      for (p2 = text; *p2 != '\0'; ++p2)
	if (*p2 < '0' || *p2 > '9')
	  {
	    if (reading_filename != 0)
	      makefile_fatal (reading_filename, *reading_lineno_ptr,
			      "non-numeric first argument to `word' function");
	    else
	      fatal ("non-numeric first argument to `word' function");
	  }

      i = (unsigned int) atoi (text);
      if (i == 0)
	{
	  if (reading_filename != 0)
	    makefile_fatal (reading_filename, *reading_lineno_ptr,
			    "the `word' function takes a one-origin \
index argument");
	  else
	    fatal ("the `word' function takes a one-origin index argument");
	}

      p2 = p3;
      while ((p = find_next_token (&p2, &len)) != 0)
