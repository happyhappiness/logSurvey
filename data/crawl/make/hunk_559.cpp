 }
 
 
+static void
+print_auto_variable (const void *item, void *arg)
+{
+  const struct variable *v = item;
+
+  if (v->origin == o_automatic)
+    print_variable (item, arg);
+}
+
+
+static void
+print_noauto_variable (const void *item, void *arg)
+{
+  const struct variable *v = item;
+
+  if (v->origin != o_automatic)
+    print_variable (item, arg);
+}
+
+
 /* Print all the variables in SET.  PREFIX is printed before
    the actual variable definitions (everything else is comments).  */
 
 void
-print_variable_set (struct variable_set *set, char *prefix)
+print_variable_set (struct variable_set *set, char *prefix, int pauto)
 {
-  hash_map_arg (&set->table, print_variable, prefix);
+  hash_map_arg (&set->table, (pauto ? print_auto_variable : print_variable),
+                prefix);
 
   fputs (_("# variable set hash-table stats:\n"), stdout);
   fputs ("# ", stdout);
