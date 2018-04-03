 error (s1, s2, s3, s4, s5, s6)
      char *s1, *s2, *s3, *s4, *s5, *s6;
 {
+  log_working_directory (1);
+
   if (makelevel == 0)
     fprintf (stderr, "%s: ", program);
   else
