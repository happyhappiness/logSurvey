       if (! create_jobserver_semaphore(job_slots - 1))
         {
           DWORD err = GetLastError();
-          fatal (NILF,_("creating jobserver semaphore: (Error %d: %s)"),
+          fatal (NILF, _("creating jobserver semaphore: (Error %ld: %s)"),
                  err, map_windows32_error_to_string(err));
         }
 #else
