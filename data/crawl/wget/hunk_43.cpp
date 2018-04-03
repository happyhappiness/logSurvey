     {
       if (HYPHENP (file))
         {
-          logfp = stdout;
+          stdlogfp = stdout;
+          logfp = stdlogfp;
         }
       else
         {
-          logfp = fopen (file, appendp ? "a" : "w");
-          if (!logfp)
+          filelogfp = fopen (file, appendp ? "a" : "w");
+          if (!filelogfp)
             {
               fprintf (stderr, "%s: %s: %s\n", exec_name, file, strerror (errno));
               exit (WGET_EXIT_GENERIC_ERROR);
             }
+          logfp = filelogfp;
         }
     }
   else
