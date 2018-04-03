   equality. Return is string-boolean, ie, the empty string is false.
  */
 static char *
-func_eq (char* o, char **argv, char *funcname)
+func_eq (char *o, char **argv, char *funcname)
 {
   int result = ! strcmp (argv[0], argv[1]);
   o = variable_buffer_output (o,  result ? "1" : "", result);
