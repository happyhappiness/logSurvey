 void
 log_close (void)
 {
-  fclose (logfp);
+  int i;
+
+  if (logfp != stdin)
+    fclose (logfp);
   save_log_p = 0;
-  FREE_MAYBE (saved_log);
-  saved_log = NULL;
-  saved_log_size = saved_log_offset = 0;
+  for (i = 0; i < SAVED_LOG_LINES; i++)
+    free_log_line (i);
+  log_line_current = -1;
+  trailing_line = 0;
 }
 
-/* Dump SAVED_LOG using logprintf(), but quit further logging to memory.
-   Also, free the memory occupied by saved_log.  */
+/* Dump saved lines to logfp. */
 static void
 log_dump (void)
 {
-  save_log_p = 0;
-  if (!saved_log)
+  int num = log_line_current;
+  FILE *fp = logfp;
+
+  if (num == -1)
     return;
-  logputs (LOG_ALWAYS, saved_log);
-  free (saved_log);
-  saved_log = NULL;
-  saved_log_size = saved_log_offset = 0;
+  if (trailing_line)
+    ROT_ADVANCE (num);
+  do
+    {
+      struct log_ln *ln = log_lines + num;
+      if (ln->content)
+	fputs (ln->content, fp);
+      ROT_ADVANCE (num);
+    }
+  while (num != log_line_current);
+  if (trailing_line)
+    if (log_lines[log_line_current].content)
+      fputs (log_lines[log_line_current].content, fp);
+  fflush (fp);
 }
 
-/* Redirect output to `wget-log' if opt.lfile is stdout.  MESSIJ is
-   printed on stdout, and should contain *exactly one* `%s', which
-   will be replaced by the log file name.
+/* Redirect output to `wget-log'.  MESSIJ is printed on stdout, and
+   should contain *exactly one* `%s', which will be replaced by the
+   log file name.
 
    If logging was not enabled, MESSIJ will not be printed.  */
 void
