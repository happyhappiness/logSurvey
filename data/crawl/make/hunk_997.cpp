   return result;
 }
 
+/* Like allocated_variable_expand, but we first expand this variable in the
+    context of the next variable set, then we append the expanded value.  */
+
+static char *
+allocated_variable_append (v)
+     struct variable *v;
+{
+  struct variable_set_list *save;
+  int len = strlen (v->name);
+  char *var = alloca (len + 4);
+  char *value;
+
+  char *obuf = variable_buffer;
+  unsigned int olen = variable_buffer_length;
+
+  variable_buffer = 0;
+
+  assert(current_variable_set_list->next != 0);
+  save = current_variable_set_list;
+  current_variable_set_list = current_variable_set_list->next;
+
+  var[0] = '$';
+  var[1] = '(';
+  strcpy (&var[2], v->name);
+  var[len+2] = ')';
+  var[len+3] = '\0';
+
+  value = variable_expand_for_file (var, 0);
+
+  current_variable_set_list = save;
+
+  value += strlen (value);
+  value = variable_buffer_output (value, " ", 1);
+  value = variable_expand_string (value, v->value, (long)-1);
+
+  value = variable_buffer;
+
+#if 0
+  /* Waste a little memory and save time.  */
+  value = xrealloc (value, strlen (value))
+#endif
+
+  variable_buffer = obuf;
+  variable_buffer_length = olen;
+
+  return value;
+}
+
 /* Like variable_expand_for_file, but the returned string is malloc'd.
    This function is called a lot.  It wants to be efficient.  */
 
