   free (archive_name_array);
   name_term ();
 
-  if (stdlis == stdout && (ferror (stdout) || fclose (stdout) != 0))
+  if (stdlis != stderr && (ferror (stdlis) || fclose (stdlis) != 0))
     FATAL_ERROR ((0, 0, _("Error in writing to standard output")));
   if (exit_status == TAREXIT_FAILURE)
     error (0, 0, _("Error exit delayed from previous errors"));
+  if (ferror (stderr) || fclose (stderr) != 0)
+    exit_status = TAREXIT_FAILURE;
   exit (exit_status);
 }
