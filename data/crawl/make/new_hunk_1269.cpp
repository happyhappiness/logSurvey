      /* Check the first argument.  */
      for (p2 = text; *p2 != '\0'; ++p2)
	if (*p2 < '0' || *p2 > '9')
          fatal (reading_file,
                 "non-numeric first argument to `wordlist' function");
      i = (unsigned int)atoi(text);
      free (text);

