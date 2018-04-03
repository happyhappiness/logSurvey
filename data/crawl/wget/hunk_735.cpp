   putchar ('\n');
 #endif
 
-  format_and_print_line (strdup (locale_title),
-			 strdup (LOCALEDIR), 
+  line = xstrdup (LOCALEDIR);
+  format_and_print_line (locale_title,
+			 line, 
 			 max_chars_per_line);
+  xfree (line);
   
-  format_and_print_line (strdup (compile_title),
-			 strdup (compilation_string),
+  line = xstrdup (compilation_string);
+  format_and_print_line (compile_title,
+			 line,
 			 max_chars_per_line);
+  xfree (line);
 
-  format_and_print_line (strdup (link_title),
-			 strdup (link_string),
+  line = xstrdup (link_string);
+  format_and_print_line (link_title,
+			 line,
 			 max_chars_per_line);
+  xfree (line);
+
   printf ("\n");
   /* TRANSLATORS: When available, an actual copyright character
      (cirle-c) should be used in preference to "(C)". */
 src/ChangeLog |  5 +++++
 src/main.c    | 22 ++++++++++------------
 2 files changed, 15 insertions(+), 12 deletions(-)
