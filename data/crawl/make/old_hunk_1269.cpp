      /* Check the first argument.  */
      for (p2 = text; *p2 != '\0'; ++p2)
	if (*p2 < '0' || *p2 > '9')
	  {
	    if (reading_filename != 0)
	      makefile_fatal (reading_filename, *reading_lineno_ptr,
			      "non-numeric first argument to `wordlist' function");
	    else
	      fatal ("non-numeric first argument to `wordlist' function");
	  }
      i = (unsigned int)atoi(text);
      free (text);

