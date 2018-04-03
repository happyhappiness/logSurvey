   char *env_wgetrc, *user_wgetrc;
   int i;
 
-  printf (_("GNU Wget %s built on %s.\n\n"), version_string, OS_TYPE);
+  if (printf (_("GNU Wget %s built on %s.\n\n"), version_string, OS_TYPE) < 0)
+    exit (3);
 
   for (i = 0; compiled_features[i] != NULL; )
     {
       int line_length = MAX_CHARS_PER_LINE;
       while ((line_length > 0) && (compiled_features[i] != NULL))
         {
-          printf ("%s ", compiled_features[i]);
+          if (printf ("%s ", compiled_features[i]))
+            exit (3);
           line_length -= strlen (compiled_features[i]) + 2;
           i++;
         }
-      printf ("\n");
+      if (printf ("\n") < 0)
+        exit (3);
     }
-  printf ("\n");
+  if (printf ("\n") < 0)
+    exit (3);
 
   /* Handle the case when $WGETRC is unset and $HOME/.wgetrc is
      absent. */
-  printf ("%s\n", wgetrc_title);
+  if (printf ("%s\n", wgetrc_title) < 0)
+    exit (3);
+
   env_wgetrc = wgetrc_env_file_name ();
   if (env_wgetrc && *env_wgetrc)
     {
-      printf (_("    %s (env)\n"), env_wgetrc);
+      if (printf (_("    %s (env)\n"), env_wgetrc) < 0)
+        exit (3);
       xfree (env_wgetrc);
     }
   user_wgetrc = wgetrc_user_file_name ();
   if (user_wgetrc)
     {
-      printf (_("    %s (user)\n"), user_wgetrc);
+      if (printf (_("    %s (user)\n"), user_wgetrc) < 0)
+        exit (3);
       xfree (user_wgetrc);
     }
 #ifdef SYSTEM_WGETRC
-  printf (_("    %s (system)\n"), SYSTEM_WGETRC);
+  if (printf (_("    %s (system)\n"), SYSTEM_WGETRC) < 0)
+    exit (3);
 #endif
 
 #ifdef ENABLE_NLS
-  format_and_print_line (locale_title,
+  if (format_and_print_line (locale_title,
                         LOCALEDIR,
-                        MAX_CHARS_PER_LINE);
+                             MAX_CHARS_PER_LINE) < 0)
+    exit (3);
 #endif /* def ENABLE_NLS */
 
   if (compilation_string != NULL)
-    format_and_print_line (compile_title,
-                           compilation_string,
-                           MAX_CHARS_PER_LINE);
+    if (format_and_print_line (compile_title,
+                               compilation_string,
+                               MAX_CHARS_PER_LINE) < 0)
+      exit (3);
 
   if (link_string != NULL)
-    format_and_print_line (link_title,
-                           link_string,
-                           MAX_CHARS_PER_LINE);
+    if (format_and_print_line (link_title,
+                               link_string,
+                               MAX_CHARS_PER_LINE) < 0)
+      exit (3);
+
+  if (printf ("\n") < 0)
+    exit (3);
 
-  printf ("\n");
   /* TRANSLATORS: When available, an actual copyright character
      (cirle-c) should be used in preference to "(C)". */
-  fputs (_("\
-Copyright (C) 2009 Free Software Foundation, Inc.\n"), stdout);
-  fputs (_("\
+  if (fputs (_("\
+Copyright (C) 2009 Free Software Foundation, Inc.\n"), stdout) < 0)
+    exit (3);
+  if (fputs (_("\
 License GPLv3+: GNU GPL version 3 or later\n\
 <http://www.gnu.org/licenses/gpl.html>.\n\
 This is free software: you are free to change and redistribute it.\n\
-There is NO WARRANTY, to the extent permitted by law.\n"), stdout);
+There is NO WARRANTY, to the extent permitted by law.\n"), stdout) < 0)
+    exit (3);
   /* TRANSLATORS: When available, please use the proper diacritics for
      names such as this one. See en_US.po for reference. */
-  fputs (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"),
-         stdout);
-  fputs (_("Please send bug reports and questions to <bug-wget@gnu.org>.\n"),
-         stdout);
+  if (fputs (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"),
+             stdout) < 0)
+    exit (3);
+  if (fputs (_("Please send bug reports and questions to <bug-wget@gnu.org>.\n"),
+             stdout) < 0)
+    exit (3);
+
   exit (0);
 }
 
