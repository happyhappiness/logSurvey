       printf ("%s (user)\n%s", user_wgetrc, prefix_spaces);
       xfree (user_wgetrc);
     }
-  printf ("%s (system)\n", system_wgetrc);
+#ifdef SYSTEM_WGETRC
+  printf ("%s (system)\n", SYSTEM_WGETRC);
+#endif
 
   format_and_print_line (strdup (locale_title),
-			 strdup (locale_dir), 
+			 strdup (LOCALEDIR), 
 			 max_chars_per_line);
   
   format_and_print_line (strdup (compile_title),
 src/ChangeLog | 8 ++++++--
 src/url.c     | 4 ++--
 2 files changed, 8 insertions(+), 4 deletions(-)
