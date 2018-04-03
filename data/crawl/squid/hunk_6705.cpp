 errorInitialize(void)
 {
     err_type i;
+    const char *text;
+    /* find this one first so we can append it to others in errorTryLoadText() */
+    for (i = ERR_NONE + 1; i < ERR_MAX; i++) {
+	safe_free(error_text[i]);
+	/* hard-coded ? */
+	if ((text = errorFindHardText(i)))
+	    error_text[i] = xstrdup(text);
+	else
+	    error_text[i] = errorLoadText(i);
+	assert(error_text[i]);
+    }
+}
+
+static const char *
+errorFindHardText(err_type type)
+{
+    int i;
+    for (i = 0; i < error_hard_text_count; i++)
+	if (error_hard_text[i].type == type)
+	    return error_hard_text[i].text;
+    return NULL;
+}
+
+
+static char *
+errorLoadText(err_type type)
+{
+    /* test configured location */
+    char *text = errorTryLoadText(type, Config.errorDirectory);
+    /* test default location if failed */
+    if (!text && strcmp(Config.errorDirectory, DEFAULT_SQUID_ERROR_DIR))
+	text = errorTryLoadText(type, DEFAULT_SQUID_ERROR_DIR);
+    /* giving up if failed */
+    if (!text)
+	fatal("failed to find or read error text file.");
+    return text;
+}
+
+static char *
+errorTryLoadText(err_type type, const char *dir)
+{
     int fd;
     char path[MAXPATHLEN];
     struct stat sb;
-    for (i = ERR_NONE + 1; i < ERR_MAX; i++) {
-	snprintf(path, MAXPATHLEN, "%s/%s",
-	    Config.errorDirectory, err_type_str[i]);
-	fd = file_open(path, O_RDONLY, NULL, NULL, NULL);
-	if (fd < 0) {
-	    debug(4, 0) ("errorInitialize: %s: %s\n", path, xstrerror());
-	    fatal("Failed to open error text file");
-	}
-	if (fstat(fd, &sb) < 0)
-	    fatal("fstat() failed on error text file");
-	safe_free(error_text[i]);
-	error_text[i] = xcalloc(sb.st_size + 1, 1);
-	if (read(fd, error_text[i], sb.st_size) != sb.st_size)
-	    fatal("failed to fully read error text file");
-	file_close(fd);
+    char *text;
+
+    snprintf(path, MAXPATHLEN, "%s/%s",
+	dir, err_type_str[type]);
+    fd = file_open(path, O_RDONLY, NULL, NULL, NULL);
+    if (fd < 0 || fstat(fd, &sb) < 0) {
+	debug(4, 0) ("errorTryLoadText: '%s': %s\n", path, xstrerror());
+	if (fd >= 0)
+	    file_close(fd);
+	return NULL;
     }
+    text = xcalloc(sb.st_size + 2 + 1, 1);
+    if (read(fd, text, sb.st_size) != sb.st_size) {
+	debug(4, 0) ("errorTryLoadText: failed to fully read: '%s': %s\n",
+	    path, xstrerror());
+	xfree(text);
+	text = NULL;
+    }
+    file_close(fd);
+    strcat(text, "%S"); /* add signature */
+    return text;
 }
 
 void
