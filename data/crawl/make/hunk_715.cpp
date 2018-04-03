   /* look one last time after reading all Makefiles */
   if (no_default_sh_exe)
     no_default_sh_exe = !find_and_set_default_shell(NULL);
-
-  if (no_default_sh_exe && job_slots != 1) {
-    error (NILF, _("Do not specify -j or --jobs if sh.exe is not available."));
-    error (NILF, _("Resetting make for single job mode."));
-    job_slots = 1;
-  }
 #endif /* WINDOWS32 */
 
 #if defined (__MSDOS__) || defined (__EMX__)
