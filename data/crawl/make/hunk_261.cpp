 
   if (d == 0)
     {
-      const char *msg_noparent
-        = _("%sNo rule to make target '%s'%s");
-      const char *msg_parent
-        = _("%sNo rule to make target '%s', needed by '%s'%s");
-
       /* Didn't find any dependencies to complain about. */
-      if (!keep_going_flag)
+      if (file->parent)
         {
-          if (file->parent == 0)
-            fatal (NILF, msg_noparent, "", file->name, "");
+          size_t l = strlen (file->name) + strlen (file->parent->name) + 4;
 
-          fatal (NILF, msg_parent, "", file->name, file->parent->name, "");
-        }
+          if (!keep_going_flag)
+            fatal (NILF, l,
+                   _("%sNo rule to make target '%s', needed by '%s'%s"),
+                   "", file->name, file->parent->name, "");
 
-      if (file->parent == 0)
-        error (NILF, msg_noparent, "*** ", file->name, ".");
+          error (NILF, l, _("%sNo rule to make target '%s', needed by '%s'%s"),
+                 "*** ", file->name, file->parent->name, ".");
+        }
       else
-        error (NILF, msg_parent, "*** ", file->name, file->parent->name, ".");
+        {
+          size_t l = strlen (file->name) + 4;
+
+          if (!keep_going_flag)
+            fatal (NILF, l,
+                   _("%sNo rule to make target '%s'%s"), "", file->name, "");
+
+          error (NILF, l,
+                 _("%sNo rule to make target '%s'%s"), "*** ", file->name, ".");
+        }
 
       file->no_diag = 0;
     }
