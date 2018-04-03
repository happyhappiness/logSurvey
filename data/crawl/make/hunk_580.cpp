 
 /* Print the data base of files.  */
 
-static void
-print_file (const void *item)
+void
+print_prereqs (const struct dep *deps)
 {
-  const struct file *f = item;
-  struct dep *d;
-  struct dep *ood = 0;
-
-  putchar ('\n');
-  if (!f->is_target)
-    puts (_("# Not a target:"));
-  printf ("%s:%s", f->name, f->double_colon ? ":" : "");
+  const struct dep *ood = 0;
 
   /* Print all normal dependencies; note any order-only deps.  */
-  for (d = f->deps; d != 0; d = d->next)
-    if (! d->ignore_mtime)
-      printf (" %s", dep_name (d));
+  for (; deps != 0; deps = deps->next)
+    if (! deps->ignore_mtime)
+      printf (" %s", dep_name (deps));
     else if (! ood)
-      ood = d;
+      ood = deps;
 
   /* Print order-only deps, if we have any.  */
   if (ood)
     {
       printf (" | %s", dep_name (ood));
-      for (d = ood->next; d != 0; d = d->next)
-        if (d->ignore_mtime)
-          printf (" %s", dep_name (d));
+      for (ood = ood->next; ood != 0; ood = ood->next)
+        if (ood->ignore_mtime)
+          printf (" %s", dep_name (ood));
     }
 
   putchar ('\n');
+}
+
+static void
+print_file (const void *item)
+{
+  const struct file *f = item;
+
+  putchar ('\n');
+  if (!f->is_target)
+    puts (_("# Not a target:"));
+  printf ("%s:%s", f->name, f->double_colon ? ":" : "");
+  print_prereqs (f->deps);
 
   if (f->precious)
     puts (_("#  Precious file (prerequisite of .PRECIOUS)."));
