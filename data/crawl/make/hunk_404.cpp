 }
 
 
+/* Write a message relating to a child.  Write it to the child's output
+   sync file if present, otherwise to the terminal.  */
+
+static void
+child_out (const struct child *child, const char *msg, int out)
+{
+  int outfd = out ? child->outfd : child->errfd;
+
+  if (outfd >= 0)
+    {
+      lseek (outfd, 0, SEEK_END);
+      write (outfd, msg, strlen (msg));
+      write (outfd, "\n", 1);
+    }
+  else
+    {
+      FILE *outf = out ? stdout : stderr;
+
+      fputs (msg, outf);
+      putc ('\n', outf);
+      fflush (outf);
+    }
+}
+
 /* Write an error message describing the exit status given in
    EXIT_CODE, EXIT_SIG, and COREDUMP, for the target TARGET_NAME.
    Append "(ignored)" if IGNORED is nonzero.  */
 
 static void
-child_error (const struct file *file,
+child_error (const struct child *child,
              int exit_code, int exit_sig, int coredump, int ignored)
 {
-  const char *nm;
   const char *pre = "*** ";
   const char *post = "";
   const char *dump = "";
-  gmk_floc *flocp = &file->cmds->fileinfo;
+  const struct file *f = child->file;
+  gmk_floc *flocp = &f->cmds->fileinfo;
+  const char *msg;
+  const char *nm;
+  unsigned int l;
 
   if (ignored && silent_flag)
     return;
