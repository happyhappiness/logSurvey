
      for (p2 = text; *p2 != '\0'; ++p2)
	if (*p2 < '0' || *p2 > '9')
          fatal (reading_file,
                 "non-numeric second argument to `wordlist' function");
      j = (unsigned int)atoi(text);
      free (text);

