  putchar ('\n');
#endif

  format_and_print_line (locale_title,
			 LOCALEDIR, 
			 max_chars_per_line);
  
  format_and_print_line (compile_title,
			 compilation_string,
			 max_chars_per_line);

  format_and_print_line (link_title,
			 link_string,
			 max_chars_per_line);

  printf ("\n");
  /* TRANSLATORS: When available, an actual copyright character
tests/ChangeLog     | 6 ++++++
tests/FTPServer.pm  | 3 +--
tests/FTPTest.pm    | 3 +--
tests/HTTPServer.pm | 3 +--
tests/HTTPTest.pm   | 3 +--
5 files changed, 10 insertions(+), 8 deletions(-)
