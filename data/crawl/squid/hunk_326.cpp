     if (Config.chroot_dir && !chrooted) {
         chrooted = true;
 
-        if (chroot(Config.chroot_dir) != 0)
-            fatalf("chroot to %s failed: %s", Config.chroot_dir, xstrerror());
+        if (chroot(Config.chroot_dir) != 0) {
+            int xerrno = errno;
+            fatalf("chroot to %s failed: %s", Config.chroot_dir, xstrerr(xerrno));
+        }
 
         if (!mainChangeDir("/"))
             fatalf("chdir to / after chroot to %s failed", Config.chroot_dir);
