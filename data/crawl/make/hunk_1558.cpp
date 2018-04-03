 int
 start_remote_job_p ()
 {
-  if (Customs_Host (EXPORT_SAME, &permit) != RPC_SUCCESS)
+  static int inited = 0;
+  int status;
+
+  /* Allow the user to turn off job exportation
+     (useful while he is debugging Customs, for example).  */
+  if (getenv ("GNU_MAKE_NO_CUSTOMS") != 0)
+    return 0;
+
+  if (!inited)
+    {
+      /* For secure Customs, make is installed setuid root and
+	 Customs requires a privileged source port be used.  */
+      make_access ();
+
+      /* Ping the daemon once to see if it is there.  */
+      inited = Customs_Ping () == RPC_SUCCESS ? 1 : -1;
+
+      /* Return to normal user access.  */
+      user_access ();
+    }
+
+  if (inited < 0)
     return 0;
 
+  status = Customs_Host (EXPORT_SAME, &permit);
+  if (status != RPC_SUCCESS)
+    {
+      if (debug_flag)
+	printf ("Customs won't export: %s\n", Rpc_ErrorMessage (status));
+      return 0;
+    }
+
   return !CUSTOMS_FAIL (&permit.addr);
 }
 
-/* Start a remote job running the command in ARGV,
-   with environment from ENVP.  It gets standard input from STDIN_FD.  On
-   failure, return nonzero.  On success, return zero, and set *USED_STDIN
-   to nonzero if it will actually use STDIN_FD, zero if not, set *ID_PTR to
-   a unique identification, and set *IS_REMOTE to zero if the job is local,
-   nonzero if it is remote (meaning *ID_PTR is a process ID).  */
+/* Start a remote job running the command in ARGV, with environment from
+   ENVP.  It gets standard input from STDIN_FD.  On failure, return
+   nonzero.  On success, return zero, and set *USED_STDIN to nonzero if it
+   will actually use STDIN_FD, zero if not, set *ID_PTR to a unique
+   identification, and set *IS_REMOTE to nonzero if the job is remote, zero
+   if it is local (meaning *ID_PTR is a process ID).  */
 
 int
 start_remote_job (argv, envp, stdin_fd, is_remote, id_ptr, used_stdin)
