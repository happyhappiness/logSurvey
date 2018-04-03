   return result;
 }
 
-/* Like allocated_variable_expand, but we first expand this variable in the
-    context of the next variable set, then we append the expanded value.  */
+/* Like allocated_variable_expand, but for += target-specific variables.
+   First recursively construct the variable value from its appended parts in
+   any upper variable sets.  Then expand the resulting value.  */
 
 static char *
-allocated_variable_append (v)
-     struct variable *v;
+variable_append (name, length, set)
+     const char *name;
+     unsigned int length;
+     const struct variable_set_list *set;
 {
-  struct variable_set_list *save;
-  int len = strlen (v->name);
-  char *var = alloca (len + 4);
-  char *value;
+  const struct variable *v;
+  char *buf = 0;
 
-  char *obuf = variable_buffer;
-  unsigned int olen = variable_buffer_length;
+  /* If there's nothing left to check, return the empty buffer.  */
+  if (!set)
+    return initialize_variable_output ();
 
-  variable_buffer = 0;
+  /* Try to find the variable in this variable set.  */
+  v = lookup_variable_in_set (name, length, set->set);
 
-  assert(current_variable_set_list->next != 0);
-  save = current_variable_set_list;
-  current_variable_set_list = current_variable_set_list->next;
+  /* If there isn't one, look to see if there's one in a set above us.  */
+  if (!v)
+    return variable_append (name, length, set->next);
 
-  var[0] = '$';
-  var[1] = '(';
-  strcpy (&var[2], v->name);
-  var[len+2] = ')';
-  var[len+3] = '\0';
+  /* If this variable type is append, first get any upper values.
+     If not, initialize the buffer.  */
+  if (v->append)
+    buf = variable_append (name, length, set->next);
+  else
+    buf = initialize_variable_output ();
 
-  value = variable_expand_for_file (var, 0);
+  /* Append this value to the buffer, and return it.
+     If we already have a value, first add a space.  */
+  if (buf > variable_buffer)
+    buf = variable_buffer_output (buf, " ", 1);
 
-  current_variable_set_list = save;
+  return variable_buffer_output (buf, v->value, strlen (v->value));
+}
+
+
+static char *
+allocated_variable_append (v)
+     const struct variable *v;
+{
+  char *val, *retval;
 
-  value += strlen (value);
-  value = variable_buffer_output (value, " ", 1);
-  value = variable_expand_string (value, v->value, (long)-1);
+  /* Construct the appended variable value.  */
 
-  value = variable_buffer;
+  char *obuf = variable_buffer;
+  unsigned int olen = variable_buffer_length;
 
-#if 0
-  /* Waste a little memory and save time.  */
-  value = xrealloc (value, strlen (value))
-#endif
+  variable_buffer = 0;
+
+  val = variable_append (v->name, strlen (v->name), current_variable_set_list);
+  variable_buffer_output (val, "", 1);
+  val = variable_buffer;
 
   variable_buffer = obuf;
   variable_buffer_length = olen;
 
-  return value;
+  /* Now expand it and return that.  */
+
+  retval = allocated_variable_expand (val);
+
+  free (val);
+  return retval;
 }
 
 /* Like variable_expand_for_file, but the returned string is malloc'd.
