   return status;
 }
 
+/* Generate an error/fatal message if no rules are available for the target.
+ */
+static void
+no_rule_error(file)
+  struct file *file;
+{
+  static const char msg_noparent[]
+    = "%sNo rule to make target `%s'%s";
+  static const char msg_parent[]
+    = "%sNo rule to make target `%s', needed by `%s'%s";
+  if (keep_going_flag || file->dontcare)
+    {
+      if (!file->dontcare)
+        {
+          if (file->parent == 0)
+            error (msg_noparent, "*** ", file->name, ".");
+          else
+            error (msg_parent, "*** ",
+                   file->name, file->parent->name, ".");
+          file->shownerror = 1;
+        }
+      file->update_status = 2;
+    }
+  else
+    {
+      if (file->parent == 0)
+        fatal (msg_noparent, "", file->name, "");
+      else
+        fatal (msg_parent, "", file->name, file->parent->name, "");
+    }
+}
+
 /* If FILE is not up to date, execute the commands for it.
    Return 0 if successful, 1 if unsuccessful;
    but with some flag settings, just call `exit' if unsuccessful.
