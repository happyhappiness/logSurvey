		 _("non-numeric second argument to `wordlist' function"));

  start = atoi (argv[0]);
  if (start < 1)
    fatal (reading_file, "invalid first argument to `wordlist' function: '%d'",
           message, start);

  count = atoi (argv[1]) - start + 1;

  if (count > 0)
