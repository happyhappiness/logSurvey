   const struct file *f = item;
 
   putchar ('\n');
+
+  if (f->cmds && f->cmds->recipe_prefix != cmd_prefix)
+    {
+      fputs (".RECIPEPREFIX = ", stdout);
+      cmd_prefix = f->cmds->recipe_prefix;
+      if (cmd_prefix != RECIPEPREFIX_DEFAULT)
+        putchar (cmd_prefix);
+      putchar ('\n');
+    }
+
+  if (f->variables != 0)
+    print_target_variables (f);
+
   if (!f->is_target)
     puts (_("# Not a target:"));
   printf ("%s:%s", f->name, f->double_colon ? ":" : "");
