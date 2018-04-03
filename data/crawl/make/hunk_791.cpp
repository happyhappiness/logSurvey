   /* Run the command.  */
   pid = exec_command (argv, envp);
 
-  /* Restore stdout/stdin of the parent process.  */
-  if (stdin_fd != 0 && dup2 (save_stdin, 0) != 0)
-    fatal (NILF, _("restoring of stdin failed\n"));
-  if (stdout_fd != 1 && dup2 (save_stdout, 1) != 1)
-    fatal (NILF, _("restoring of stdout failed\n"));
+  /* Restore stdout/stdin of the parent and close temporary FDs.  */
+  if (stdin_fd != 0)
+    {
+      if (dup2 (save_stdin, 0) != 0)
+        fatal (NILF, _("Could not restore stdin\n"));
+      else
+        close (save_stdin);
+    }
+
+  if (stdout_fd != 1)
+    {
+      if (dup2 (save_stdout, 1) != 1)
+        fatal (NILF, _("Could not restore stdout\n"));
+      else
+        close (save_stdout);
+    }
 
   return pid;
 }
