   return o;
 }
 
+static char *
+func_lastword (char *o, char **argv, const char *funcname UNUSED)
+{
+  unsigned int i;
+  char *words = argv[0];    /* Use a temp variable for find_next_token */
+  char *p = 0;
+  char *t;
+
+  while ((t = find_next_token (&words, &i)))
+    p = t;
+
+  if (p != 0)
+    o = variable_buffer_output (o, p, i);
+
+  return o;
+}
 
 static char *
 func_words (char *o, char **argv, const char *funcname UNUSED)
