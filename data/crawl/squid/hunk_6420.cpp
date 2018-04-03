     return 1;
 }
 
-static void
-storeCreateDirectory(const char *path, int lvl)
+static int
+storeCreateDirectory(const char *path, int should_exist)
 {
+    int created = 0;
     struct stat st;
-    if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
-	debug(20, lvl) ("%s exists\n", path);
-    } else if (mkdir(path, 0755) == 0) {
-	debug(20, lvl) ("%s created\n", path);
-    } else if (errno == EEXIST) {
-	debug(20, lvl) ("%s exists\n", path);
+    if (0 == stat(path, &st)) {
+	if (S_ISDIR(st.st_mode)) {
+	    debug(20, should_exist ? 3 : 1) ("%s exists\n", path);
+	} else {
+	    snprintf(tmp_error_buf, ERROR_BUF_SZ,
+		"Swap directory %s is not a directory.", path);
+	    fatal(tmp_error_buf);
+	}
+    } else if (0 == mkdir(path, 0755)) {
+	debug(20, should_exist ? 1 : 3) ("%s created\n", path);
+	created = 1;
     } else {
 	snprintf(tmp_error_buf, ERROR_BUF_SZ,
 	    "Failed to make swap directory %s: %s",
 	    path, xstrerror());
 	fatal(tmp_error_buf);
     }
+    return created;
 }
 
 static int
