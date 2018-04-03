 void
 define_new_function(const gmk_floc *flocp,
                     const char *name, int min, int max, int expand,
-                    char *(*func)(char *, char **, const char *))
+                    char *(*func)(const char *, int, char **))
 {
+  struct function_table_entry *ent;
   size_t len = strlen (name);
-  struct function_table_entry *ent = xmalloc (sizeof (struct function_table_entry));
 
   if (len > 255)
     fatal (flocp, _("Function name too long: %s\n"), name);
   if (min < 0 || min > 255)
     fatal (flocp, _("Invalid minimum argument count (%d) for function %s\n"),
            min, name);
-  if (max < 0 || max > 255 || max < min)
+  if (max < 0 || max > 255 || (max && max < min))
     fatal (flocp, _("Invalid maximum argument count (%d) for function %s\n"),
            max, name);
 
+  ent = xmalloc (sizeof (struct function_table_entry));
   ent->name = name;
   ent->len = len;
   ent->minimum_args = min;
   ent->maximum_args = max;
   ent->expand_args = expand ? 1 : 0;
-  ent->func_ptr = func;
+  ent->alloc_fn = 1;
+  ent->fptr.alloc_func_ptr = func;
 
   hash_insert (&function_table, ent);
 }
