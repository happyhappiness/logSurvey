 	if (need_close)
 		close(fd);
 }
+
+static const char *quote_crnl(const char *path)
+{
+	static char new_path[PATH_MAX];
+	const char *p2 = path;
+	char *p1 = new_path;
+
+	if (!path)
+		return NULL;
+
+	while (*p2) {
+		switch (*p2) {
+		case '\\': *p1++ = '\\'; *p1++ = '\\'; break;
+		case '\n': *p1++ = '\\'; *p1++ = 'n'; break;
+		case '\r': *p1++ = '\\'; *p1++ = 'r'; break;
+		default:
+			*p1++ = *p2;
+		}
+		p2++;
+	}
+	*p1 = '\0';
+	return new_path;
+}
+
+/* FIXME: move prefix to startup_info struct and get rid of this arg */
+void trace_repo_setup(const char *prefix)
+{
+	char cwd[PATH_MAX];
+	char *trace = getenv("GIT_TRACE");
+
+	if (!trace || !strcmp(trace, "") ||
+	    !strcmp(trace, "0") || !strcasecmp(trace, "false"))
+		return;
+
+	if (!getcwd(cwd, PATH_MAX))
+		die("Unable to get current working directory");
+
+	trace_printf("setup: git_dir: %s\n", quote_crnl(get_git_dir()));
+	trace_printf("setup: worktree: %s\n", quote_crnl(get_git_work_tree()));
+	trace_printf("setup: cwd: %s\n", quote_crnl(cwd));
+	trace_printf("setup: prefix: %s\n", quote_crnl(prefix));
+}