  line_dup = xstrdup (line);

  if (line_length <= 0)
    line_length = max_chars_per_line;

  leading_spaces = strlen (prefix);
  printf ("%s", prefix);
  remaining_chars = line_length - leading_spaces;
  /* We break on spaces. */
  token = strtok (line_dup, " ");
  while (token != NULL) 
