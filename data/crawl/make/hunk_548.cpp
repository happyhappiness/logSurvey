      have written all our tokens so do that now.  If tokens are left
      after any other error code, that's bad.  */
 
+#ifdef WINDOWS32
+  if (has_jobserver_semaphore() && jobserver_tokens)
+#else
   if (job_fds[0] != -1 && jobserver_tokens)
+#endif
     {
       if (status != 2)
         error (NILF,
