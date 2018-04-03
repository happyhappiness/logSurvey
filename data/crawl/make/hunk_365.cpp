       cp = jobserver_fds->list[0];
 
 #ifdef WINDOWS32
-      if (! open_jobserver_semaphore(cp))
+      if (! open_jobserver_semaphore (cp))
         {
-          DWORD err = GetLastError();
+          DWORD err = GetLastError ();
           fatal (NILF, _("internal error: unable to open jobserver semaphore '%s': (Error %ld: %s)"),
-                 cp, err, map_windows32_error_to_string(err));
+                 cp, err, map_windows32_error_to_string (err));
         }
       DB (DB_JOBS, (_("Jobserver client (semaphore %s)\n"), cp));
 #else
