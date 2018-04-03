 }
 
 /*
+  $(eval <makefile string>)
+
+  Always resolves to the empty string.
+
+  Treat the arguments as a segment of makefile, and parse them.
+*/
+
+static char *
+func_eval (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  eval_buffer (argv[0]);
+
+  return o;
+}
+
+
+static char *
+func_value (o, argv, funcname)
+     char *o;
+     char **argv;
+     const char *funcname;
+{
+  /* Look up the variable.  */
+  struct variable *v = lookup_variable (argv[0], strlen (argv[0]));
+
+  /* Copy its value into the output buffer without expanding it.  */
+  if (v)
+    o = variable_buffer_output (o, v->value, strlen(v->value));
+
+  return o;
+}
+
+/*
   \r  is replaced on UNIX as well. Is this desirable?
  */
 void
