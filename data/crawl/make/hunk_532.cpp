 }
 
 void
+define_new_function(const struct floc *flocp,
+                    const char *name, int min, int max, int expand,
+                    char *(*func)(char *, char **, const char *))
+{
+  size_t len = strlen (name);
+  struct function_table_entry *ent = xmalloc (sizeof (struct function_table_entry));
+
+  if (len > 255)
+    fatal (flocp, _("Function name too long: %s\n"), name);
+  if (min < 0 || min > 255)
+    fatal (flocp, _("Invalid minimum argument count (%d) for function %s%s\n"),
+           min, name);
+  if (max < 0 || max > 255 || max < min)
+    fatal (flocp, _("Invalid maximum argument count (%d) for function %s%s\n"),
+           max, name);
+
+  ent->name = name;
+  ent->len = len;
+  ent->minimum_args = min;
+  ent->maximum_args = max;
+  ent->expand_args = expand ? 1 : 0;
+  ent->func_ptr = func;
+
+  hash_insert (&function_table, ent);
+}
+
+void
 hash_init_function_table (void)
 {
   hash_init (&function_table, FUNCTION_TABLE_ENTRIES * 2,
