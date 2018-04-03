 {
   if (file)
     {
-      logfp = fopen (file, appendp ? "a" : "w");
-      if (!logfp)
+      if (HYPHENP (file))
         {
-          fprintf (stderr, "%s: %s: %s\n", exec_name, file, strerror (errno));
-          exit (WGET_EXIT_GENERIC_ERROR);
+          logfp = stdout;
+        }
+      else
+        {
+          logfp = fopen (file, appendp ? "a" : "w");
+          if (!logfp)
+            {
+              fprintf (stderr, "%s: %s: %s\n", exec_name, file, strerror (errno));
+              exit (WGET_EXIT_GENERIC_ERROR);
+            }
         }
     }
   else
