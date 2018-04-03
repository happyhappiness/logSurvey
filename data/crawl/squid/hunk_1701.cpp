         chrooted = true;
 
         if (chroot(Config.chroot_dir) != 0);
-            fatal("failed to chroot");
+        fatal("failed to chroot");
 
         strncpy(pathbuf, "/", sizeof(pathbuf)-1);
     }