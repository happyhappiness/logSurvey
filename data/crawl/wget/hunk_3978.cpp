   logfp = fopen (logfile, "w");
   if (!logfp)
     {
-      printf ("%s: %s: %s\n", exec_name, logfile, strerror (errno));
-      /* `stdin' is magic to not print anything.  */
+      /* Eek!  Opening the alternate log file has failed.  Nothing we
+         can do but disable printing completely. */
+      fprintf (stderr, "%s: %s: %s\n", exec_name, logfile, strerror (errno));
+      /* `stdin' is magic to not print anything, ever.  */
       logfp = stdin;
     }
-  printf (messij, logfile);
+  fprintf (stderr, messij, logfile);
   free (logfile);
-  /* Dump all the previous messages to LOGFILE.  */
+  /* Dump the previous screenful of output to LOGFILE.  */
   log_dump ();
+  save_log_p = 0;
 }
