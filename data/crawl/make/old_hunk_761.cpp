		 _("non-numeric second argument to `wordlist' function"));

  start = atoi (argv[0]);
  count = atoi (argv[1]) - start + 1;

  if (count > 0)
