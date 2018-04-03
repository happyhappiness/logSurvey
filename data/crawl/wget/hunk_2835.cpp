     {
       fprintf (stderr, _("%s: Cannot read %s (%s).\n"), exec_name,
 	       file, strerror (errno));
-      return 1;			/* not a fatal error */
+      return true;			/* not a fatal error */
     }
-  enable_tilde_expansion = 1;
+  enable_tilde_expansion = true;
   ln = 1;
   while ((line = read_whole_line (fp)) != NULL)
     {
