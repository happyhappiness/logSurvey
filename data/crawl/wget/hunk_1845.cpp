   return buf;
 }
 
+/* Function that prints the line argument while limiting it
+   to at most line_length. prefix is printed on the first line
+   and an appropriate number of spaces are added on subsequent
+   lines.*/
+static void
+format_and_print_line (char* prefix, char* line,
+		       int line_length) 
+{
+  assert (prefix != NULL);
+  assert (line != NULL);
+
+  if (line_length <= 0)
+    line_length = max_chars_per_line;
+
+  const int leading_spaces = strlen (prefix);
+  printf ("%s", prefix);
+  int remaining_chars = line_length - leading_spaces;
+  /* We break on spaces. */
+  char* token = strtok (line, " ");
+  while (token != NULL) 
+    {
+      /* If however a token is much larger than the maximum
+         line length, all bets are off and we simply print the
+         token on the next line. */
+      if (remaining_chars <= strlen (token)) 
+        {
+          printf ("\n");
+          int j = 0;
+          for (j = 0; j < leading_spaces; j++) 
+            {
+              printf (" ");
+            }
+          remaining_chars = line_length - leading_spaces;
+        }
+      printf ("%s ", token);
+      remaining_chars -= strlen (token) + 1;  // account for " "
+      token = strtok (NULL, " ");
+    }
+
+  printf ("\n");
+  xfree (prefix);
+  xfree (line);
+}
+
 static void
 print_version (void)
 {
-  printf ("GNU Wget %s\n\n", version_string);
+  const char *options_title = "Options    : ";
+  const char *wgetrc_title  = "Wgetrc     : ";
+  const char *locale_title  = "Locale     : ";
+  const char *compile_title = "Compile    : ";
+  const char *link_title    = "Link       : ";
+  const char *prefix_spaces = "             ";
+  const int prefix_space_length = strlen (prefix_spaces);
+
+  printf ("GNU Wget %s\n", version_string);
+  printf (options_title);
+  /* compiled_features is a char*[]. We limit the characters per
+     line to max_chars_per_line and prefix each line with a constant
+     number of spaces for proper alignment. */
+  int i =0;
+  for (i = 0; compiled_features[i] != NULL; ) 
+    {
+      int line_length = max_chars_per_line - prefix_space_length;
+      while ((line_length > 0) && (compiled_features[i] != NULL)) 
+        {
+          printf ("%s ", compiled_features[i]);
+          line_length -= strlen (compiled_features[i]) + 2;
+          i++;
+        }
+      printf ("\n");
+      if (compiled_features[i] != NULL) 
+        {
+	  printf (prefix_spaces);
+        }
+    }
+  /* Handle the case when $WGETRC is unset and $HOME/.wgetrc is 
+     absent. */
+  printf (wgetrc_title);
+  char *env_wgetrc = wgetrc_env_file_name ();
+  if (env_wgetrc && *env_wgetrc) 
+    {
+      printf ("%s (env)\n%s", env_wgetrc, prefix_spaces);
+      xfree (env_wgetrc);
+    }
+  char *user_wgetrc = wgetrc_user_file_name ();
+  if (user_wgetrc) 
+    {
+      printf ("%s (user)\n%s", user_wgetrc, prefix_spaces);
+      xfree (user_wgetrc);
+    }
+  printf ("%s (system)\n", system_wgetrc);
+
+  format_and_print_line (strdup (locale_title),
+			 strdup (locale_dir), 
+			 max_chars_per_line);
+  
+  format_and_print_line (strdup (compile_title),
+			 strdup (compilation_string),
+			 max_chars_per_line);
+
+  format_and_print_line (strdup (link_title),
+			 strdup (link_string),
+			 max_chars_per_line);
+  printf ("\n");
   /* TRANSLATORS: When available, an actual copyright character
      (cirle-c) should be used in preference to "(C)". */
   fputs (_("\
