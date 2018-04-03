      char **argv, **envp;
 {
 #ifdef VMS
-    /* Run the program.  */
-    execve (argv[0], argv, envp);
-    perror_with_name ("execve: ", argv[0]);
-    _exit (EXIT_FAILURE);
+  /* Run the program.  */
+  execve (argv[0], argv, envp);
+  perror_with_name ("execve: ", argv[0]);
+  _exit (EXIT_FAILURE);
 #else
+#ifdef WINDOWS32
+  HANDLE hPID;
+  HANDLE hWaitPID;
+  int err = 0;
+  int exit_code = EXIT_FAILURE;
+
+  /* make sure CreateProcess() has Path it needs */
+  sync_Path_environment();
+
+  /* launch command */
+  hPID = process_easy(argv, envp);
+
+  /* make sure launch ok */
+  if (hPID == INVALID_HANDLE_VALUE)
+    {
+      int i;
+      fprintf(stderr,
+              "process_easy() failed failed to launch process (e=%d)\n",
+              process_last_err(hPID));
+      for (i = 0; argv[i]; i++)
+          fprintf(stderr, "%s ", argv[i]);
+      fprintf(stderr, "\nCounted %d args in failed launch\n", i);
+      exit(EXIT_FAILURE);
+    }
+
+  /* wait and reap last child */
+  while (hWaitPID = process_wait_for_any())
+    {
+      /* was an error found on this process? */
+      err = process_last_err(hWaitPID);
+
+      /* get exit data */
+      exit_code = process_exit_code(hWaitPID);
+
+      if (err)
+          fprintf(stderr, "make (e=%d, rc=%d): %s",
+                  err, exit_code, map_windows32_error_to_string(err));
+
+      /* cleanup process */
+      process_cleanup(hWaitPID);
+
+      /* expect to find only last pid, warn about other pids reaped */
+      if (hWaitPID == hPID)
+          break;
+      else
+          fprintf(stderr,
+                  "make reaped child pid %d, still waiting for pid %d\n",
+                  hWaitPID, hPID);
+    }
+
+  /* return child's exit code as our exit code */
+  exit(exit_code);
+
+#else  /* !WINDOWS32 */
+
   /* Be the user, permanently.  */
   child_access ();
 
