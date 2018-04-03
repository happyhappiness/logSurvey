format_and_print_line (char* prefix, char* line,
		       int line_length) 
{
  int leading_spaces;
  int remaining_chars;
  char *token;
  
  assert (prefix != NULL);
  assert (line != NULL);

  if (line_length <= 0)
    line_length = max_chars_per_line;

  leading_spaces = strlen (prefix);
  printf ("%s", prefix);
  remaining_chars = line_length - leading_spaces;
  /* We break on spaces. */
  token = strtok (line, " ");
  while (token != NULL) 
    {
      /* If however a token is much larger than the maximum
