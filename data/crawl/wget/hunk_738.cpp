   putchar ('\n');
 #endif
 
-  line = xstrdup (LOCALEDIR);
   format_and_print_line (locale_title,
-			 line, 
+			 LOCALEDIR, 
 			 max_chars_per_line);
-  xfree (line);
   
-  line = xstrdup (compilation_string);
   format_and_print_line (compile_title,
-			 line,
+			 compilation_string,
 			 max_chars_per_line);
-  xfree (line);
 
-  line = xstrdup (link_string);
   format_and_print_line (link_title,
-			 line,
+			 link_string,
 			 max_chars_per_line);
-  xfree (line);
 
   printf ("\n");
   /* TRANSLATORS: When available, an actual copyright character
 tests/ChangeLog     | 6 ++++++
 tests/FTPServer.pm  | 3 +--
 tests/FTPTest.pm    | 3 +--
 tests/HTTPServer.pm | 3 +--
 tests/HTTPTest.pm   | 3 +--
 5 files changed, 10 insertions(+), 8 deletions(-)
