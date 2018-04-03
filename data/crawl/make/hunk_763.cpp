     }
 #endif
 
+#ifndef MAKE_SYMLINKS
+  if (check_symlink_flag)
+    {
+      error (NILF, _("Symbolic links not supported: disabling -L."));
+      check_symlink_flag = 0;
+    }
+#endif
+
   /* Set up MAKEFLAGS and MFLAGS again, so they will be right.  */
 
   define_makeflags (1, 0);
