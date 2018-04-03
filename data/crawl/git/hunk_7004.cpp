 	timer_fn = handler;
 	return old;
 }
+
+static const char *make_backslash_path(const char *path)
+{
+	static char buf[PATH_MAX + 1];
+	char *c;
+
+	if (strlcpy(buf, path, PATH_MAX) >= PATH_MAX)
+		die("Too long path: %.*s", 60, path);
+
+	for (c = buf; *c; c++) {
+		if (*c == '/')
+			*c = '\\';
+	}
+	return buf;
+}
+
+void mingw_open_html(const char *unixpath)
+{
+	const char *htmlpath = make_backslash_path(unixpath);
+	printf("Launching default browser to display HTML ...\n");
+	ShellExecute(NULL, "open", htmlpath, NULL, "\\", 0);
+}
