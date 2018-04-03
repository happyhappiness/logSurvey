   return cvt_scm_to_str (scm_c_eval_string (arg));
 }
 
-/* ----- Public interface ----- */
-
-/* This is the make interface for passing programs to Guile.  */
-char *
-guile_eval_string (char *str)
+/* This is the function registered with make  */
+static char *
+func_guile (char *o, char **argv, const char *funcname UNUSED)
 {
-  return scm_with_guile (internal_guile_eval, str);
+  if (argv[0] && argv[0][0] != '\0')
+    {
+      char *str = scm_with_guile (internal_guile_eval, argv[0]);
+      o = variable_buffer_output (o, str, strlen (str));
+      free (str);
+    }
+
+  return o;
 }
 
-void
+/* ----- Public interface ----- */
+
+int
 setup_guile ()
 {
+  /* Initialize the Guile interpreter.  */
   scm_with_guile (guile_init, NULL);
 
+  /* Create a make function "guile".  */
+  define_new_function (NILF, "guile", 0, 1, 1, func_guile);
+
   /* Add 'guile' to the list of features. */
   do_variable_definition (NILF, ".FEATURES", "guile", o_default, f_append, 0);
+
+  return 1;
 }
