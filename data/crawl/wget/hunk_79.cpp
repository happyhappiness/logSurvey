   int status;
   int com[2];
   ssize_t bytes = 0;
-  char * const argv[] = { opt.use_askpass, question, NULL };
+  char *argv[3], *p;
   posix_spawn_file_actions_t fa;
 
   if (pipe (com) == -1)
     {
-      fprintf (stderr, _("Cannot create pipe"));
+      fprintf (stderr, _("Cannot create pipe\n"));
       exit (WGET_EXIT_GENERIC_ERROR);
     }
 
