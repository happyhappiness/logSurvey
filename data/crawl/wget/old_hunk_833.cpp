  putchar ('\n');
#endif

  format_and_print_line (strdup (locale_title),
			 strdup (LOCALEDIR), 
			 max_chars_per_line);
  
  format_and_print_line (strdup (compile_title),
			 strdup (compilation_string),
			 max_chars_per_line);

  format_and_print_line (strdup (link_title),
			 strdup (link_string),
			 max_chars_per_line);
  printf ("\n");
  /* TRANSLATORS: When available, an actual copyright character
     (cirle-c) should be used in preference to "(C)". */
src/ChangeLog |  5 +++++
src/main.c    | 22 ++++++++++------------
2 files changed, 15 insertions(+), 12 deletions(-)
