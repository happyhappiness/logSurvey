     /* send signal to running copy and exit */
     if (opt_send_signal != -1) {
         /* chroot if configured to run inside chroot */
-
+        mainSetCwd();
         if (Config.chroot_dir) {
-            if (chroot(Config.chroot_dir))
-                fatal("failed to chroot");
-
             no_suid();
         } else {
             leave_suid();