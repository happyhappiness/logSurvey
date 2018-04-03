  remaining_chars = line_length;
  /* We break on spaces. */
  token = strtok (line_dup, " ");
  while (token != NULL) 
    {
      /* If however a token is much larger than the maximum
         line length, all bets are off and we simply print the
         token on the next line. */
      if (remaining_chars <= strlen (token)) 
        {
          printf ("\n%*c", TABULATION, ' ');
          remaining_chars = line_length - TABULATION;
