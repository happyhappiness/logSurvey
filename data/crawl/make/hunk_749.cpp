       if (print_data_base_flag)
 	print_data_base ();
 
-      /* Sanity: have we written all our jobserver tokens back?  */
+      /* Sanity: have we written all our jobserver tokens back?  If our
+         exit status is 2 that means some kind of syntax error; we might not
+         have written all our tokens so do that now.  If tokens are left
+         after any other error code, that's bad.  */
+
+      if (job_fds[0] != -1 && jobserver_tokens)
+        {
+          if (status != 2)
+            error (NILF,
+                   "INTERNAL: Exiting with %u jobserver tokens (should be 0)!",
+                   jobserver_tokens);
+          else
+            while (jobserver_tokens--)
+              {
+                int r;
+
+                EINTRLOOP (r, write (job_fds[1], &token, 1));
+                if (r != 1)
+                  perror_with_name ("write", "");
+              }
+        }
 
-      if (jobserver_tokens)
-        error (NILF,
-               "INTERNAL: Exiting with %u jobserver tokens (should be 0)!",
-               jobserver_tokens);
 
       /* Sanity: If we're the master, were all the tokens written back?  */
 
       if (master_job_slots)
         {
-          char token;
           /* We didn't write one for ourself, so start at 1.  */
           unsigned int tcnt = 1;
 
