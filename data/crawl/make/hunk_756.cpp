       if (print_data_base_flag)
 	print_data_base ();
 
+      /* Sanity: have we written all our jobserver tokens back?  */
+
+      if (jobserver_tokens)
+        error (NILF,
+               "INTERNAL: Exiting with %u jobserver tokens (should be 0)!",
+               jobserver_tokens);
+
+      /* Sanity: If we're the master, were all the tokens written back?  */
+
+      if (master_job_slots)
+        {
+          char token;
+          /* We didn't write one for ourself, so start at 1.  */
+          unsigned int tcnt = 1;
+
+          /* Close the write side, so the read() won't hang.  */
+          close (job_fds[1]);
+
+          while ((err = read (job_fds[0], &token, 1)) == 1)
+            ++tcnt;
+
+          if (tcnt != master_job_slots)
+            error (NILF,
+                   "INTERNAL: Exiting with %u jobserver tokens available; should be %u!",
+                   tcnt, master_job_slots);
+        }
+
       /* Try to move back to the original directory.  This is essential on
 	 MS-DOS (where there is really only one process), and on Unix it
 	 puts core files in the original directory instead of the -C
