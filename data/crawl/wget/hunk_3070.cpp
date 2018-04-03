 static void
 ws_hangup (const char *reason)
 {
-  /* Whether we arrange our own version of opt.lfilename here.  */
-  int changedp = 0;
-
-  if (!opt.lfilename)
-    {
-      opt.lfilename = unique_name (DEFAULT_LOGFILE, 0);
-      changedp = 1;
-    }
-  printf (_("Continuing in background.\n"));
-  if (changedp)
-    printf (_("Output will be written to `%s'.\n"), opt.lfilename);
-
+  fprintf (stderr, _("Continuing in background.\n"));
   log_request_redirect_output (reason);
 
   /* Detach process from the current console.  Under Windows 9x, if we
