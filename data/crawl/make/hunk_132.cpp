 func_shell_base (char *o, char **argv, int trim_newlines)
 {
   fprintf (stderr, "This platform does not support shell\n");
-  die (EXIT_FAILURE);
+  die (MAKE_TROUBLE);
   return NULL;
 }
 
