       if (! release_jobserver_semaphore ())
         {
           DWORD err = GetLastError ();
-          fatal (NILF, _("release jobserver semaphore: (Error %ld: %s)"),
-                 err, map_windows32_error_to_string (err));
+          const char *estr = map_windows32_error_to_string (err);
+          OSN (fatal, NILF,
+               _("release jobserver semaphore: (Error %ld: %s)"), err, estr);
         }
 
       DB (DB_JOBS, (_("Released token for child %p (%s).\n"), child, child->file->name));
