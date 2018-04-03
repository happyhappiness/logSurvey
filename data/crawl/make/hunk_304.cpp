 static void
 free_child (struct child *child)
 {
-  if (child->outfd >= 0)
-    close (child->outfd);
-  if (child->errfd >= 0 && child->errfd != child->outfd)
-    close (child->errfd);
+  output_close (&child->output);
 
   if (!jobserver_tokens)
     fatal (NILF, "INTERNAL: Freeing child %p (%s) but no tokens left!\n",
