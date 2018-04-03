                         MAX_CHARS_PER_LINE);
 #endif /* def ENABLE_NLS */
 
-  format_and_print_line (compile_title,
-			 compilation_string,
-			 MAX_CHARS_PER_LINE);
+  if (compilation_string != NULL)
+    format_and_print_line (compile_title,
+                           compilation_string,
+                           MAX_CHARS_PER_LINE);
 
-  format_and_print_line (link_title,
-			 link_string,
-			 MAX_CHARS_PER_LINE);
+  if (link_string != NULL)
+    format_and_print_line (link_title,
+                           link_string,
+                           MAX_CHARS_PER_LINE);
 
   printf ("\n");
   /* TRANSLATORS: When available, an actual copyright character
