     no_default_sh_exe = !find_and_set_default_shell(NULL);
 
   if (no_default_sh_exe && job_slots != 1) {
-    error("Do not specify -j or --jobs if sh.exe is not available.");
-    error("Resetting make for single job mode.");
+    error (NILF, "Do not specify -j or --jobs if sh.exe is not available.");
+    error (NILF, "Resetting make for single job mode.");
     job_slots = 1;
   }
 #endif /* WINDOWS32 */
