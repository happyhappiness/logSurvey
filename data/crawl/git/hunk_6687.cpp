 	}
 }
 
+static void check_attr_stdin_paths(int cnt, struct git_attr_check *check,
+	const char** name)
+{
+	struct strbuf buf, nbuf;
+	int line_termination = null_term_line ? 0 : '\n';
+
+	strbuf_init(&buf, 0);
+	strbuf_init(&nbuf, 0);
+	while (strbuf_getline(&buf, stdin, line_termination) != EOF) {
+		if (line_termination && buf.buf[0] == '"') {
+			strbuf_reset(&nbuf);
+			if (unquote_c_style(&nbuf, buf.buf, NULL))
+				die("line is badly quoted");
+			strbuf_swap(&buf, &nbuf);
+		}
+		check_attr(cnt, check, name, buf.buf);
+		maybe_flush_or_die(stdout, "attribute to stdout");
+	}
+	strbuf_release(&buf);
+	strbuf_release(&nbuf);
+}
+
 int cmd_check_attr(int argc, const char **argv, const char *prefix)
 {
 	struct git_attr_check *check;
 	int cnt, i, doubledash;
+	const char *errstr = NULL;
+
+	argc = parse_options(argc, argv, check_attr_options, check_attr_usage,
+		PARSE_OPT_KEEP_DASHDASH);
+	if (!argc)
+		usage_with_options(check_attr_usage, check_attr_options);
 
 	if (read_cache() < 0) {
 		die("invalid cache");
 	}
 
 	doubledash = -1;
-	for (i = 1; doubledash < 0 && i < argc; i++) {
+	for (i = 0; doubledash < 0 && i < argc; i++) {
 		if (!strcmp(argv[i], "--"))
 			doubledash = i;
 	}
 
 	/* If there is no double dash, we handle only one attribute */
 	if (doubledash < 0) {
 		cnt = 1;
-		doubledash = 1;
+		doubledash = 0;
 	} else
-		cnt = doubledash - 1;
+		cnt = doubledash;
 	doubledash++;
 
-	if (cnt <= 0 || argc < doubledash)
-		usage(check_attr_usage);
+	if (cnt <= 0)
+		errstr = "No attribute specified";
+	else if (stdin_paths && doubledash < argc)
+		errstr = "Can't specify files with --stdin";
+	if (errstr) {
+		error (errstr);
+		usage_with_options(check_attr_usage, check_attr_options);
+	}
+
 	check = xcalloc(cnt, sizeof(*check));
 	for (i = 0; i < cnt; i++) {
 		const char *name;
 		struct git_attr *a;
-		name = argv[i + 1];
+		name = argv[i];
 		a = git_attr(name, strlen(name));
 		if (!a)
 			return error("%s: not a valid attribute name", name);
 		check[i].attr = a;
 	}
 
-	for (i = doubledash; i < argc; i++)
-		check_attr(cnt, check, argv+1, argv[i]);
-	maybe_flush_or_die(stdout, "attribute to stdout");
+	if (stdin_paths)
+		check_attr_stdin_paths(cnt, check, argv);
+	else {
+		for (i = doubledash; i < argc; i++)
+			check_attr(cnt, check, argv, argv[i]);
+		maybe_flush_or_die(stdout, "attribute to stdout");
+	}
 	return 0;
 }
