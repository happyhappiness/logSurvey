 func_origin (char *o, char **argv, const char *funcname UNUSED)
 {
   /* Expand the argument.  */
-  register struct variable *v = lookup_variable (argv[0], strlen (argv[0]));
+  struct variable *v = lookup_variable (argv[0], strlen (argv[0]));
   if (v == 0)
     o = variable_buffer_output (o, "undefined", 9);
   else
