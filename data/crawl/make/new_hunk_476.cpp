
  /* Check the arguments.  */
  check_numeric (argv[0],
		 _("non-numeric first argument to 'wordlist' function"));
  check_numeric (argv[1],
		 _("non-numeric second argument to 'wordlist' function"));

  start = atoi (argv[0]);
  if (start < 1)
    fatal (*expanding_var,
           "invalid first argument to 'wordlist' function: '%d'", start);

  count = atoi (argv[1]) - start + 1;

