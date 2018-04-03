 }
 
 void
-jobserver_parse_arg (const char* arg)
+jobserver_parse_auth (const char *auth)
 {
   jobserver_semaphore = OpenSemaphore (
   SEMAPHORE_ALL_ACCESS,   /* Semaphore access setting */
     FALSE,                  /* Child processes DON'T inherit */
-    arg);                   /* Semaphore name */
+    auth);                   /* Semaphore name */
 
   if (jobserver_semaphore == NULL)
     {
       DWORD err = GetLastError ();
       const char *estr = map_windows32_error_to_string (err);
-      fatal (NILF, strlen (arg) + INTSTR_LENGTH + strlen (estr),
+      fatal (NILF, strlen (auth) + INTSTR_LENGTH + strlen (estr),
              _("internal error: unable to open jobserver semaphore '%s': (Error %ld: %s)"),
-             arg, err, estr);
+             auth, err, estr);
     }
-  DB (DB_JOBS, (_("Jobserver client (semaphore %s)\n"), arg));
+  DB (DB_JOBS, (_("Jobserver client (semaphore %s)\n"), auth));
 }
 
 char *
-jobserver_get_arg ()
+jobserver_get_auth ()
 {
-  char *fds = xmalloc (MAX_PATH + 1);
-  strcpy (fds, jobserver_semaphore_name);
-  return fds;
+  return xstrdup (jobserver_semaphore_name);
 }
 
 unsigned int
