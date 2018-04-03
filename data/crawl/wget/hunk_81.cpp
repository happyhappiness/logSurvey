   if (status)
     {
       fprintf (stderr,
-              _("Error setting spawn file actions for use-askpass: %d"),
+              _("Error setting spawn file actions for use-askpass: %d\n"),
               status);
       exit (WGET_EXIT_GENERIC_ERROR);
     }
 
+  /* C89 initializer lists must be computable at load time,
+   * thus this explicit initialization. */
+  argv[0] = opt.use_askpass;
+  argv[1] = question;
+  argv[2] = NULL;
+
   status = posix_spawnp (&pid, opt.use_askpass, &fa, NULL, argv, environ);
   if (status)
     {
-      fprintf (stderr, "Error spawning %s: %d", opt.use_askpass, status);
+      fprintf (stderr, "Error spawning %s: %d\n", opt.use_askpass, status);
       exit (WGET_EXIT_GENERIC_ERROR);
     }
 
