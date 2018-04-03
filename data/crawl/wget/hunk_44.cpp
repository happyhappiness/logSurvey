 
 /* When SIGHUP or SIGUSR1 are received, the output is redirected
    elsewhere.  Such redirection is only allowed once. */
-static enum { RR_NONE, RR_REQUESTED, RR_DONE } redirect_request = RR_NONE;
 static const char *redirect_request_signal_name;
 
-/* Redirect output to `wget-log'.  */
+/* Redirect output to `wget-log' or back to stdout/stderr.  */
 
-static void
-redirect_output (void)
+void
+redirect_output (bool to_file, const char *signal_name)
 {
-  char *logfile;
-  logfp = unique_create (DEFAULT_LOGFILE, false, &logfile);
-  if (logfp)
+  if (to_file && logfp != filelogfp)
     {
-      fprintf (stderr, _("\n%s received, redirecting output to %s.\n"),
-               redirect_request_signal_name, quote (logfile));
-      xfree (logfile);
-      /* Dump the context output to the newly opened log.  */
-      log_dump_context ();
+      if (signal_name)
+        {
+          fprintf (stderr, "\n%s received.", signal_name);
+        }
+      if (!filelogfp)
+        {
+          filelogfp = unique_create (DEFAULT_LOGFILE, false, &logfile);
+          if (filelogfp)
+            {
+              fprintf (stderr, _("\nRedirecting output to %s.\n"),
+                  quote (logfile));
+              /* Store signal name to tell wget it's permanent redirect to log file */
+              redirect_request_signal_name = signal_name;
+              logfp = filelogfp;
+              /* Dump the context output to the newly opened log.  */
+              log_dump_context ();
+            }
+          else
+            {
+              /* Eek!  Opening the alternate log file has failed.  Nothing we
+                can do but disable printing completely. */
+              fprintf (stderr, _("%s: %s; disabling logging.\n"),
+                      (logfile) ? logfile : DEFAULT_LOGFILE, strerror (errno));
+              inhibit_logging = true;
+            }
+        }
+      else
+        {
+          fprintf (stderr, _("\nRedirecting output to %s.\n"),
+              quote (logfile));
+          logfp = filelogfp;
+          log_dump_context ();
+        }
     }
-  else
+  else if (!to_file && logfp != stdlogfp)
     {
-      /* Eek!  Opening the alternate log file has failed.  Nothing we
-         can do but disable printing completely. */
-      fprintf (stderr, _("\n%s received.\n"), redirect_request_signal_name);
-      fprintf (stderr, _("%s: %s; disabling logging.\n"),
-               (logfile) ? logfile : DEFAULT_LOGFILE, strerror (errno));
-      inhibit_logging = true;
+      logfp = stdlogfp;
+      log_dump_context ();
     }
-  save_context_p = false;
 }
 
-/* Check whether a signal handler requested the output to be
-   redirected. */
+/* Check whether there's a need to redirect output. */
 
 static void
 check_redirect_output (void)
 {
-  if (redirect_request == RR_REQUESTED)
+#ifndef WINDOWS
+  /* If it was redirected already to log file by SIGHUP or SIGUSR1,
+   * it was permanent and since that redirect_request_signal_name is set.
+   * If there was no SIGHUP or SIGUSR1 and shell is interactive
+   * we check if process is fg or bg before every line is printed.*/
+  if (!redirect_request_signal_name && shell_is_interactive)
     {
-      redirect_request = RR_DONE;
-      redirect_output ();
+      if (tcgetpgrp (STDIN_FILENO) != getpgrp ())
+        {
+          // Process backgrounded
+          redirect_output (true,NULL);
+        }
+      else
+        {
+          // Process foregrounded
+          redirect_output (false,NULL);
+        }
     }
-}
-
-/* Request redirection at a convenient time.  This may be called from
-   a signal handler. */
-
-void
-log_request_redirect_output (const char *signal_name)
-{
-  if (redirect_request == RR_NONE && save_context_p)
-    /* Request output redirection.  The request will be processed by
-       check_redirect_output(), which is called from entry point log
-       functions. */
-    redirect_request = RR_REQUESTED;
-  redirect_request_signal_name = signal_name;
+#endif /* WINDOWS */
 }
