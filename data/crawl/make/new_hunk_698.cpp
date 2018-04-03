
  start = atoi (argv[0]);
  if (start < 1)
    fatal (*expanding_var,
           "invalid first argument to `wordlist' function: `%d'", start);

  count = atoi (argv[1]) - start + 1;
