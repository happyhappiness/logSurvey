      /* Check the first argument.  */
      for (p2 = text; *p2 != '\0'; ++p2)
	if (*p2 < '0' || *p2 > '9')
          fatal (reading_file,
                 "non-numeric first argument to `word' function");

      i = (unsigned int) atoi (text);
      if (i == 0)
        fatal (reading_file,
               "the `word' function takes a one-origin index argument");

      p2 = p3;
      while ((p = find_next_token (&p2, &len)) != 0)
