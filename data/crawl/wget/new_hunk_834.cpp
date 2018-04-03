  printf ("%s", prefix);
  remaining_chars = line_length - leading_spaces;
  /* We break on spaces. */
  token = strtok (line_dup, " ");
  while (token != NULL) 
    {
      /* If however a token is much larger than the maximum
