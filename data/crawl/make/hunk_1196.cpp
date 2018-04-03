 }
 #endif /* WINDOWS32 */
 
+
+#ifndef MAKE_JOBSERVER
+# define free_job_token(c)
+#else
+static void
+free_job_token (child)
+     struct child *child;
+{
+  switch (child->job_token)
+  {
+    case '-':
+      /* If this child doesn't have a token, punt.  */
+      return;
+
+    case '+':
+      /* If this child has the reserved token, take it back.  */
+      my_job_token = '+';
+      break;
+
+    default:
+      /* Write any other job tokens back to the pipe.  */
+      write (job_fds[1], &child->job_token, 1);
+      break;
+  }
+
+  if (debug_flag)
+    printf ("Released token `%c' for child 0x%08lx (%s).\n",
+            child->job_token, (unsigned long int) child, child->file->name);
+
+  child->job_token = '-';
+}
+#endif
+
+
 /* Write an error message describing the exit status given in
    EXIT_CODE, EXIT_SIG, and COREDUMP, for the target TARGET_NAME.
    Append "(ignored)" if IGNORED is nonzero.  */
