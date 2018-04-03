 requirePathnameExists(const char *name, const char *path)
 {
     struct stat sb;
+    char pathbuf[BUFSIZ];
     assert(path != NULL);
+    if (Config.chroot_dir) {
+	snprintf(pathbuf, BUFSIZ, "%s/%s", Config.chroot_dir, path);
+	path = pathbuf;
+    }
     if (stat(path, &sb) < 0)
-	fatalf("%s: %s", path, xstrerror());
+	fatalf("%s %s: %s", name, path, xstrerror());
 }
 
 char *