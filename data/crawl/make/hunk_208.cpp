       if (job_slots > 0)
         {
           if (! restarts)
-            error (NILF, _("warning: -jN forced in submake: disabling jobserver mode."));
+            O (error, NILF,
+               _("warning: -jN forced in submake: disabling jobserver mode."));
         }
 #ifndef WINDOWS32
 #ifdef HAVE_FCNTL
