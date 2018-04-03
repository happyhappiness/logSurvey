 {
   fprintf (stderr, "This platform does not support shell\n");
   die (EXIT_FAILURE);
+  return NULL;
 }
 
 #define func_shell 0
