static void
print_version (void)
{
  const char *wgetrc_title  = _("Wgetrc: ");
  const char *locale_title  = _("Locale: ");
  const char *compile_title = _("Compile: ");
  const char *link_title    = _("Link: ");
  char *line;
  char *env_wgetrc, *user_wgetrc;
  int i;

  printf (_("GNU Wget %s\n\n"), version_string);
  /* compiled_features is a char*[]. We limit the characters per
     line to MAX_CHARS_PER_LINE and prefix each line with a constant
     number of spaces for proper alignment. */
  for (i = 0; compiled_features[i] != NULL; ) 
    {
      int line_length = MAX_CHARS_PER_LINE;
      while ((line_length > 0) && (compiled_features[i] != NULL)) 
        {
          printf ("%s ", compiled_features[i]);
