   {
     char *cp;
 
-    if (jobserver_fds->max > 1)
-      fatal (NILF, _("internal error: multiple --jobserver-fds options."));
+    if (jobserver_fds->idx > 1)
+      fatal (NILF, _("internal error: multiple --jobserver-fds options"));
 
-    if (job_slots > 0)
-      fatal (NILF, _("internal error: --jobserver-fds unexpected."));
+    /* The combination of a pipe + !job_slots means we're using the
+       jobserver.  If !job_slots and we don't have a pipe, we can start
+       infinite jobs.  */
+
+    if (job_slots != 0)
+      fatal (NILF, _("internal error: --jobserver-fds unexpected"));
 
     /* Now parse the fds string and make sure it has the proper format.  */
 
