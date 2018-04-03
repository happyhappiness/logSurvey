  const char *link_title    = "Link       : ";
  const char *prefix_spaces = "             ";
  const int prefix_space_length = strlen (prefix_spaces);
  char *env_wgetrc, *user_wgetrc;
  int i;

  printf ("GNU Wget %s\n", version_string);
  printf (options_title);
  /* compiled_features is a char*[]. We limit the characters per
     line to max_chars_per_line and prefix each line with a constant
     number of spaces for proper alignment. */
  for (i = 0; compiled_features[i] != NULL; ) 
    {
      int line_length = max_chars_per_line - prefix_space_length;
