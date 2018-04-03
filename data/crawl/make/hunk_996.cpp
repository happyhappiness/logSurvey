      unsigned int length;
 {
   register struct variable *v = lookup_variable (name, length);
+  char *value;
 
   if (v == 0)
     warn_undefined (name, length);
 
-  if (v != 0 && *v->value != '\0')
-    {
-      char *value = (v->recursive ? recursively_expand (v) : v->value);
-      o = variable_buffer_output (o, value, strlen (value));
-      if (v->recursive)
-	free (value);
-    }
+  if (v == 0 || *v->value == '\0')
+    return o;
+
+  value = (v->recursive ? recursively_expand (v) : v->value);
+
+  o = variable_buffer_output (o, value, strlen (value));
+
+  if (v->recursive)
+    free (value);
 
   return o;
 }
