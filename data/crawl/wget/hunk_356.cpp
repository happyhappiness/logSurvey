 
 /* Print the usage message.  */
 static void
-print_usage (void)
+print_usage (int error)
 {
-  printf (_("Usage: %s [OPTION]... [URL]...\n"), exec_name);
+  fprintf (error ? stderr : stdout, _("Usage: %s [OPTION]... [URL]...\n"),
+           exec_name);
 }
 
 /* Print the help message, describing all the available options.  If
