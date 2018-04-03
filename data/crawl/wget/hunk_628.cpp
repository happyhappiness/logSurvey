   line_dup = xstrdup (line);
 
   if (line_length <= 0)
-    line_length = max_chars_per_line;
+    line_length = MAX_CHARS_PER_LINE - TABULATION;
 
-  leading_spaces = strlen (prefix);
   printf ("%s", prefix);
-  remaining_chars = line_length - leading_spaces;
+  remaining_chars = line_length;
   /* We break on spaces. */
   token = strtok (line_dup, " ");
   while (token != NULL) 
