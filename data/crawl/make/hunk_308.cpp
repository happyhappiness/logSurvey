           int _x UNUSED;
           _x = chdir (directory_before_chdir);
         }
-
-      log_working_directory (0, 0);
     }
 
   exit (status);
 }
-
-/* Write a message indicating that we've just entered or
-   left (according to ENTERING) the current directory.  */
-
-void
-log_working_directory (int entering, int force)
-{
-  static int entered = 0;
-
-  /* Print nothing without the flag.  Don't print the entering message
-     again if we already have.  Don't print the leaving message if we
-     haven't printed the entering message.  */
-  if (! print_directory_flag || (!force && entering == entered))
-    return;
-
-  if (!force)
-    entered = entering;
-
-  if (print_data_base_flag)
-    fputs ("# ", stdout);
-
-  /* Use entire sentences to give the translators a fighting chance.  */
-
-  if (makelevel == 0)
-    if (starting_directory == 0)
-      if (entering)
-        printf (_("%s: Entering an unknown directory\n"), program);
-      else
-        printf (_("%s: Leaving an unknown directory\n"), program);
-    else
-      if (entering)
-        printf (_("%s: Entering directory '%s'\n"),
-                program, starting_directory);
-      else
-        printf (_("%s: Leaving directory '%s'\n"),
-                program, starting_directory);
-  else
-    if (starting_directory == 0)
-      if (entering)
-        printf (_("%s[%u]: Entering an unknown directory\n"),
-                program, makelevel);
-      else
-        printf (_("%s[%u]: Leaving an unknown directory\n"),
-                program, makelevel);
-    else
-      if (entering)
-        printf (_("%s[%u]: Entering directory '%s'\n"),
-                program, makelevel, starting_directory);
-      else
-        printf (_("%s[%u]: Leaving directory '%s'\n"),
-                program, makelevel, starting_directory);
-
-  /* Flush stdout to be sure this comes before any stderr output.  */
-  fflush (stdout);
-}
