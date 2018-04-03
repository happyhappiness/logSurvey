        (ignore the jobserver pipe for this make) but print a message.  */
 
     if (job_slots > 0)
-      error (NILF, _("warning: -jN set for submakes: ignoring jobserver."));
+      error (NILF,
+             _("warning: -jN forced in submake: disabling jobserver mode."));
 
     /* Create a duplicate pipe, that will be closed in the SIGCHLD
        handler.  If this fails with EBADF, the parent has closed the pipe
