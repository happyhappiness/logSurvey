 	}
 }
 
+static void append_path(struct grep_opt *opt, const void *data, size_t len)
+{
+	struct string_list *path_list = opt->output_priv;
+
+	if (len == 1 && *(const char *)data == '\0')
+		return;
+	string_list_append(xstrndup(data, len), path_list);
+}
+
+static void run_pager(struct grep_opt *opt, const char *prefix)
+{
+	struct string_list *path_list = opt->output_priv;
+	const char **argv = xmalloc(sizeof(const char *) * (path_list->nr + 1));
+	int i, status;
+
+	for (i = 0; i < path_list->nr; i++)
+		argv[i] = path_list->items[i].string;
+	argv[path_list->nr] = NULL;
+
+	if (prefix && chdir(prefix))
+		die("Failed to chdir: %s", prefix);
+	status = run_command_v_opt(argv, RUN_USING_SHELL);
+	if (status)
+		exit(status);
+	free(argv);
+}
+
 static int grep_cache(struct grep_opt *opt, const char **paths, int cached)
 {
 	int hit = 0;
