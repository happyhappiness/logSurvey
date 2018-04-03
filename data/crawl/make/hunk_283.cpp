 }
 
 void
-define_new_function (const gmk_floc *flocp,
-                     const char *name, int min, int max, int expand,
-                     char *(*func)(const char *, int, char **))
+define_new_function (const gmk_floc *flocp, const char *name,
+                     unsigned int min, unsigned int max, unsigned int flags,
+                     gmk_func_ptr func)
 {
+  const char *e = name;
   struct function_table_entry *ent;
-  size_t len = strlen (name);
+  size_t len;
+
+  while (STOP_SET (*e, MAP_USERFUNC))
+    e++;
+  len = e - name;
 
+  if (len == 0)
+    fatal (flocp, _("Empty function name\n"));
+  if (*name == '.' || *e != '\0')
+    fatal (flocp, _("Invalid function name: %s\n"), name);
   if (len > 255)
     fatal (flocp, _("Function name too long: %s\n"), name);
-  if (min < 0 || min > 255)
+  if (min > 255)
     fatal (flocp, _("Invalid minimum argument count (%d) for function %s\n"),
            min, name);
-  if (max < 0 || max > 255 || (max && max < min))
+  if (max > 255 || (max && max < min))
     fatal (flocp, _("Invalid maximum argument count (%d) for function %s\n"),
            max, name);
 
