 {
     free_all();
 }
+
+static void
+requirePathnameExists(const char *name, const char *path)
+{
+    struct stat sb;
+    char buf[MAXPATHLEN];
+    assert(path != NULL);
+    if (stat(path, &sb) < 0) {
+	snprintf(buf, MAXPATHLEN, "%s: %s", path, xstrerror());
+	fatal(buf);
+    }
+}
