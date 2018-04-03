  putchar ('\n');
#endif

  line = xstrdup (LOCALEDIR);
  format_and_print_line (locale_title,
			 line, 
			 max_chars_per_line);
  xfree (line);
  
  line = xstrdup (compilation_string);
  format_and_print_line (compile_title,
			 line,
			 max_chars_per_line);
  xfree (line);

  line = xstrdup (link_string);
  format_and_print_line (link_title,
			 line,
			 max_chars_per_line);
  xfree (line);

  printf ("\n");
  /* TRANSLATORS: When available, an actual copyright character
     (cirle-c) should be used in preference to "(C)". */
src/ChangeLog |  5 +++++
src/main.c    | 22 ++++++++++------------
2 files changed, 15 insertions(+), 12 deletions(-)
