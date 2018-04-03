       else
 	{
 	  if (debug_flag)
-	    printf ("Reaping %s child 0x%08lx PID %d%s\n",
+	    printf ("Reaping %s child 0x%08lx PID %ld%s\n",
 		    child_failed ? "losing" : "winning",
 		    (unsigned long int) c,
-		    c->pid, c->remote ? " (remote)" : "");
+		    (long) c->pid, c->remote ? " (remote)" : "");
+
+      if (c->sh_batch_file) {
+         if (debug_flag)
+           printf("Cleaning up temporary batch file %s\n", c->sh_batch_file);
+
+         /* just try and remove, don't care if this fails */
+         remove(c->sh_batch_file);
+
+         /* all done with memory */
+         free(c->sh_batch_file);
+         c->sh_batch_file = NULL;
+      }
 
 	  /* If this child had the good stdin, say it is now free.  */
 	  if (c->good_stdin)
