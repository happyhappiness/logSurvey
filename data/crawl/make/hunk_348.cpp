       /* Loop until child_handler or reap_children()  sets
          shell_function_completed to the status of our child shell.  */
       while (shell_function_completed == 0)
-	reap_children (1, 0);
+        reap_children (1, 0);
 
-      if (batch_filename) {
-	DB (DB_VERBOSE, (_("Cleaning up temporary batch file %s\n"),
-                       batch_filename));
-	remove (batch_filename);
-	free (batch_filename);
-      }
+      if (batch_filename)
+        {
+          DB (DB_VERBOSE, (_("Cleaning up temporary batch file %s\n"),
+                           batch_filename));
+          remove (batch_filename);
+          free (batch_filename);
+        }
       shell_function_pid = 0;
 
       /* The child_handler function will set shell_function_completed
-	 to 1 when the child dies normally, or to -1 if it
-	 dies with status 127, which is most likely an exec fail.  */
+         to 1 when the child dies normally, or to -1 if it
+         dies with status 127, which is most likely an exec fail.  */
 
       if (shell_function_completed == -1)
-	{
-	  /* This likely means that the execvp failed, so we should just
-	     write the error message in the pipe from the child.  */
-	  fputs (buffer, stderr);
-	  fflush (stderr);
-	}
+        {
+          /* This likely means that the execvp failed, so we should just
+             write the error message in the pipe from the child.  */
+          fputs (buffer, stderr);
+          fflush (stderr);
+        }
       else
-	{
-	  /* The child finished normally.  Replace all newlines in its output
-	     with spaces, and put that in the variable output buffer.  */
-	  fold_newlines (buffer, &i, trim_newlines);
-	  o = variable_buffer_output (o, buffer, i);
-	}
+        {
+          /* The child finished normally.  Replace all newlines in its output
+             with spaces, and put that in the variable output buffer.  */
+          fold_newlines (buffer, &i, trim_newlines);
+          o = variable_buffer_output (o, buffer, i);
+        }
 
       free (buffer);
     }
