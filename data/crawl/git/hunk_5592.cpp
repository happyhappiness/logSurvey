 	strbuf_reset(buf);
 }
 
+static int push_dav(int nr_spec, char **specs)
+{
+	const char **argv = xmalloc((10 + nr_spec) * sizeof(char*));
+	int argc = 0, i;
+
+	argv[argc++] = "http-push";
+	argv[argc++] = "--helper-status";
+	if (options.dry_run)
+		argv[argc++] = "--dry-run";
+	if (options.verbosity > 1)
+		argv[argc++] = "--verbose";
+	argv[argc++] = url;
+	for (i = 0; i < nr_spec; i++)
+		argv[argc++] = specs[i];
+	argv[argc++] = NULL;
+
+	if (run_command_v_opt(argv, RUN_GIT_CMD))
+		die("git-%s failed", argv[0]);
+	free(argv);
+	return 0;
+}
+
+static void parse_push(struct strbuf *buf)
+{
+	char **specs = NULL;
+	int alloc_spec = 0, nr_spec = 0, i;
+
+	do {
+		if (!prefixcmp(buf->buf, "push ")) {
+			ALLOC_GROW(specs, nr_spec + 1, alloc_spec);
+			specs[nr_spec++] = xstrdup(buf->buf + 5);
+		}
+		else
+			die("http transport does not support %s", buf->buf);
+
+		strbuf_reset(buf);
+		if (strbuf_getline(buf, stdin, '\n') == EOF)
+			return;
+		if (!*buf->buf)
+			break;
+	} while (1);
+
+	if (push_dav(nr_spec, specs))
+		exit(128); /* error already reported */
+	for (i = 0; i < nr_spec; i++)
+		free(specs[i]);
+	free(specs);
+
+	printf("\n");
+	fflush(stdout);
+}
+
 int main(int argc, const char **argv)
 {
 	struct strbuf buf = STRBUF_INIT;
