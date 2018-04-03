     return fullpath;
 }
 
+static void
+storeCreateDirectory(const char *path, int lvl)
+{
+    struct stat st;
+    if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
+	debug(20, lvl) ("%s exists\n", path);
+    } else if (mkdir(path, 0755) == 0) {
+	debug(20, lvl) ("%s created\n", path);
+    } else if (errno == EEXIST) {
+	debug(20, lvl) ("%s exists\n", path);
+    } else {
+	snprintf(tmp_error_buf, ERROR_BUF_SZ,
+	    "Failed to make swap directory %s: %s",
+	    path, xstrerror());
+	fatal(tmp_error_buf);
+    }
+}
+
 static int
-storeVerifyOrCreateDir(const char *path)
+storeVerifyDirectory(const char *path)
 {
     struct stat sb;
-    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
-	debug(47, 3) ("%s exists\n", path);
-	return 0;
+    if (stat(path, &sb) < 0) {
+	debug(20, 0) ("%s: %s\n", path, xstrerror());
+	return -1;
     }
-    safeunlink(path, 1);
-    if (mkdir(path, 0777) < 0) {
-	if (errno != EEXIST) {
-	    snprintf(tmp_error_buf, ERROR_BUF_SZ,
-		"Failed to create swap directory %s: %s",
-		path,
-		xstrerror());
-	    fatal(tmp_error_buf);
-	}
+    if (S_ISDIR(sb.st_mode) == 0) {
+	debug(20, 0) ("%s is not a directory\n", path);
+	return -1;
     }
-    debug(47, 1) ("Created directory %s\n", path);
-    if (stat(path, &sb) < 0 || !S_ISDIR(sb.st_mode)) {
-	snprintf(tmp_error_buf, ERROR_BUF_SZ,
-	    "Failed to create directory %s: %s", path, xstrerror());
-	fatal(tmp_error_buf);
-    }
-    return 1;
+    return 0;
 }
 
+/*
+ * This function is called by storeInit().  If this returns < 0,
+ * then Squid exits, complains about swap directories not
+ * existing, and instructs the admin to run 'squid -z'
+ */
 int
-storeVerifySwapDirs(void)
+storeVerifyCacheDirs(void)
+{
+    int i;
+    int j;
+    const char *path;
+    for (i = 0; i < Config.cacheSwap.n_configured; i++) {
+	path = Config.cacheSwap.swapDirs[i].path;
+	if (storeVerifyDirectory(path) < 0)
+	    return -1;
+	for (j = 0; j < Config.cacheSwap.swapDirs[i].l1; j++) {
+	    path = storeSwapSubDir(i, j);
+	    if (storeVerifyDirectory(path) < 0)
+		return -1;
+	}
+    }
+    return 0;
+}
+
+void
+storeCreateSwapDirectories(void)
 {
     int i;
     const char *path = NULL;
-    int directory_created = 0;
     for (i = 0; i < Config.cacheSwap.n_configured; i++) {
 	path = Config.cacheSwap.swapDirs[i].path;
-	debug(47, 3) ("storeVerifySwapDirs: Creating swap space in %s\n", path);
-	storeVerifyOrCreateDir(path);
+	debug(47, 3) ("Creating swap space in %s\n", path);
+	storeCreateDirectory(path, 0);
 	storeCreateSwapSubDirs(i);
     }
-    return directory_created;
 }
 
-void
+static void
 storeCreateSwapSubDirs(int j)
 {
     int i, k;
     SwapDir *SD = &Config.cacheSwap.swapDirs[j];
     LOCAL_ARRAY(char, name, MAXPATHLEN);
     for (i = 0; i < SD->l1; i++) {
 	snprintf(name, MAXPATHLEN, "%s/%02X", SD->path, i);
-	if (storeVerifyOrCreateDir(name) == 0)
-	    continue;
+	storeCreateDirectory(name, 0);
 	debug(47, 1) ("Making directories in %s\n", name);
 	for (k = 0; k < SD->l2; k++) {
 	    snprintf(name, MAXPATHLEN, "%s/%02X/%02X", SD->path, i, k);
-	    storeVerifyOrCreateDir(name);
+	    storeCreateDirectory(name, 2);
 	}
     }
 }
 
-int
+static int
 storeMostFreeSwapDir(void)
 {
     double least_used = 1.0;