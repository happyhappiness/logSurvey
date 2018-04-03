   if (line_length <= 0)
     line_length = MAX_CHARS_PER_LINE - TABULATION;
 
-  printf ("%s", prefix);
+  if (printf ("%s", prefix) < 0)
+    return -1;
   remaining_chars = line_length;
   /* We break on spaces. */
   token = strtok (line_dup, " ");
