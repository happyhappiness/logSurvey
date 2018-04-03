 static void
 memfatal (const char *what)
 {
-  /* HACK: expose save_log_p from log.c, so we can turn it off in
-     order to prevent saving the log.  Saving the log is dangerous
-     because logprintf() and logputs() can call malloc(), so this
-     could infloop.  When logging is turned off, infloop can no longer
-     happen.
-
-     #### This is no longer really necessary because the new routines
-     in log.c cons only if the line exceeds eighty characters.  But
-     this can come at the end of a line, so it's OK to be careful.
-
-     On a more serious note, it would be good to have a
-     log_forced_shutdown() routine that exposes this cleanly.  */
-  extern int save_log_p;
-
-  save_log_p = 0;
+  /* Make sure we don't try to store part of the log line, and thus
+     call malloc.  */
+  log_set_save_context (0);
   logprintf (LOG_ALWAYS, _("%s: %s: Not enough memory.\n"), exec_name, what);
   exit (1);
 }
