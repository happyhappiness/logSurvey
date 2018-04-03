  char *env_wgetrc, *user_wgetrc;
  int i;

  printf (_("GNU Wget %s built on %s.\n\n"), version_string, OS_TYPE);

  for (i = 0; compiled_features[i] != NULL; )
    {
      int line_length = MAX_CHARS_PER_LINE;
      while ((line_length > 0) && (compiled_features[i] != NULL))
        {
          printf ("%s ", compiled_features[i]);
          line_length -= strlen (compiled_features[i]) + 2;
          i++;
        }
      printf ("\n");
    }
  printf ("\n");

  /* Handle the case when $WGETRC is unset and $HOME/.wgetrc is
     absent. */
  printf ("%s\n", wgetrc_title);
  env_wgetrc = wgetrc_env_file_name ();
  if (env_wgetrc && *env_wgetrc)
    {
      printf (_("    %s (env)\n"), env_wgetrc);
      xfree (env_wgetrc);
    }
  user_wgetrc = wgetrc_user_file_name ();
  if (user_wgetrc)
    {
      printf (_("    %s (user)\n"), user_wgetrc);
      xfree (user_wgetrc);
    }
#ifdef SYSTEM_WGETRC
  printf (_("    %s (system)\n"), SYSTEM_WGETRC);
#endif

#ifdef ENABLE_NLS
  format_and_print_line (locale_title,
                        LOCALEDIR,
                        MAX_CHARS_PER_LINE);
#endif /* def ENABLE_NLS */

  if (compilation_string != NULL)
    format_and_print_line (compile_title,
                           compilation_string,
                           MAX_CHARS_PER_LINE);

  if (link_string != NULL)
    format_and_print_line (link_title,
                           link_string,
                           MAX_CHARS_PER_LINE);

  printf ("\n");
  /* TRANSLATORS: When available, an actual copyright character
     (cirle-c) should be used in preference to "(C)". */
  fputs (_("\
Copyright (C) 2009 Free Software Foundation, Inc.\n"), stdout);
  fputs (_("\
License GPLv3+: GNU GPL version 3 or later\n\
<http://www.gnu.org/licenses/gpl.html>.\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n"), stdout);
  /* TRANSLATORS: When available, please use the proper diacritics for
     names such as this one. See en_US.po for reference. */
  fputs (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"),
         stdout);
  fputs (_("Please send bug reports and questions to <bug-wget@gnu.org>.\n"),
         stdout);
  exit (0);
}

