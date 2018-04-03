       if (! create_jobserver_semaphore (job_slots - 1))
         {
           DWORD err = GetLastError ();
-          fatal (NILF, _("creating jobserver semaphore: (Error %ld: %s)"),
-                 err, map_windows32_error_to_string (err));
+          const char *estr = map_windows32_error_to_string (err);
+          OSN (fatal, NILF,
+               _("creating jobserver semaphore: (Error %ld: %s)"), err, estr);
         }
 #else
       char c = '+';
