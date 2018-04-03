   /* If we're using the jobserver and this child is not the only outstanding
      job, put a token back into the pipe for it.  */
 
+#ifdef WINDOWS32
+  if (has_jobserver_semaphore() && jobserver_tokens > 1)
+    {
+      if (! release_jobserver_semaphore())
+        {
+          DWORD err = GetLastError();
+          fatal (NILF,_("release jobserver semaphore: (Error %d: %s)"),
+                 err, map_windows32_error_to_string(err));
+        }
+
+      DB (DB_JOBS, (_("Released token for child %p (%s).\n"), child, child->file->name));
+    }
+#else
   if (job_fds[1] >= 0 && jobserver_tokens > 1)
     {
       char token = '+';
