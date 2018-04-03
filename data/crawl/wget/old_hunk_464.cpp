  /* compiled_features is a char*[]. We limit the characters per
     line to MAX_CHARS_PER_LINE and prefix each line with a constant
     number of spaces for proper alignment. */
  for (i = 0; compiled_features[i] != NULL; ) 
    {
      int line_length = MAX_CHARS_PER_LINE;
      while ((line_length > 0) && (compiled_features[i] != NULL)) 
        {
          printf ("%s ", compiled_features[i]);
          line_length -= strlen (compiled_features[i]) + 2;
