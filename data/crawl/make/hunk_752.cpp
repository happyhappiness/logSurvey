 static void
 free_child (struct child *child)
 {
-  /* If this child is the only one it was our "free" job, so don't put a
-     token back for it.  This child has already been removed from the list,
-     so if there any left this wasn't the last one.  */
+  if (!jobserver_tokens)
+    fatal (NILF, "INTERNAL: Freeing child 0x%08lx (%s) but no tokens left!\n",
+           (unsigned long int) child, child->file->name);
+
+  /* If we're using the jobserver and this child is not the only outstanding
+     job, put a token back into the pipe for it.  */
 
-  if (job_fds[1] >= 0 && children)
+  if (job_fds[1] >= 0 && jobserver_tokens > 1)
     {
       char token = '+';
       int r;
