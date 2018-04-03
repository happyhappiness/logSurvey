    Append "(ignored)" if IGNORED is nonzero.  */
 
 static void
-child_error (const char *target_name,
+child_error (const struct file *file,
              int exit_code, int exit_sig, int coredump, int ignored)
 {
+  const char *nm;
+  const char *pre = "*** ";
+  const char *post = "";
+  const char *dump = "";
+  struct floc *flocp = &file->cmds->fileinfo;
+
   if (ignored && silent_flag)
     return;
 
+  if (exit_sig && coredump)
+    dump = _(" (core dumped)");
+
+  if (ignored)
+    {
+      pre = "";
+      post = _(" (ignored)");
+    }
+
+  if (! flocp->filenm)
+    nm = _("<builtin>");
+  else
+    {
+      char *a = alloca (strlen (flocp->filenm) + 1 + 11 + 1);
+      sprintf (a, "%s:%lu", flocp->filenm, flocp->lineno);
+      nm = a;
+    }
+  message (0, _("%s: recipe for target `%s' failed"), nm, file->name);
+
 #ifdef VMS
   if (!(exit_code & 1))
-      error (NILF,
-             (ignored ? _("*** [%s] Error 0x%x (ignored)")
-              : _("*** [%s] Error 0x%x")),
-             target_name, exit_code);
+    error (NILF, _("%s[%s] Error 0x%x%s"), pre, file->name, exit_code, post);
 #else
   if (exit_sig == 0)
-    error (NILF, ignored ? _("[%s] Error %d (ignored)") :
-	   _("*** [%s] Error %d"),
-	   target_name, exit_code);
+    error (NILF, _("%s[%s] Error %d%s"), pre, file->name, exit_code, post);
   else
-    error (NILF, "*** [%s] %s%s",
-	   target_name, strsignal (exit_sig),
-	   coredump ? _(" (core dumped)") : "");
+    error (NILF, _("%s[%s] %s%s%s"),
+           pre, file->name, strsignal (exit_sig), dump, post);
 #endif /* VMS */
 }
 
