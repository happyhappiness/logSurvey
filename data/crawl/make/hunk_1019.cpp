 #ifdef __MSDOS__
   if (job_slots != 1)
     {
-      error (NILF, _("Parallel jobs (-j) are not supported on MS-DOS."));
-      error (NILF, _("Resetting to single job mode."));
+      error (NILF,
+             _("Parallel jobs (-j) are not supported on this platform."));
+      error (NILF, _("Resetting to single job (-j1) mode."));
       job_slots = 1;
     }
 #endif
