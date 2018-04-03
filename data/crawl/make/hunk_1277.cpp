 		    (unsigned long int) c,
 		    (long) c->pid, c->remote ? " (remote)" : "");
 
-      if (c->sh_batch_file) {
-         if (debug_flag)
-           printf("Cleaning up temporary batch file %s\n", c->sh_batch_file);
+          if (c->sh_batch_file) {
+            if (debug_flag)
+              printf("Cleaning up temp batch file %s\n", c->sh_batch_file);
 
-         /* just try and remove, don't care if this fails */
-         remove(c->sh_batch_file);
+            /* just try and remove, don't care if this fails */
+            remove(c->sh_batch_file);
 
-         /* all done with memory */
-         free(c->sh_batch_file);
-         c->sh_batch_file = NULL;
-      }
+            /* all done with memory */
+            free(c->sh_batch_file);
+            c->sh_batch_file = NULL;
+          }
 
 	  /* If this child had the good stdin, say it is now free.  */
 	  if (c->good_stdin)
