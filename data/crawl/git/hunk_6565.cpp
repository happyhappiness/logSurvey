 	return git_default_config(var, value, cb);
 }
 
+static int option_parse_stdin(const struct option *opt,
+			      const char *arg, int unset)
+{
+	int *errs = opt->value;
+
+	*errs |= apply_patch(0, "<stdin>", options);
+	read_stdin = 0;
+	return 0;
+}
+
+static int option_parse_exclude(const struct option *opt,
+				const char *arg, int unset)
+{
+	add_name_limit(arg, 1);
+	return 0;
+}
+
+static int option_parse_include(const struct option *opt,
+				const char *arg, int unset)
+{
+	add_name_limit(arg, 0);
+	has_include = 1;
+	return 0;
+}
+
+static int option_parse_p(const struct option *opt,
+			  const char *arg, int unset)
+{
+	p_value = atoi(arg);
+	p_value_known = 1;
+	return 0;
+}
+
+static int option_parse_z(const struct option *opt,
+			  const char *arg, int unset)
+{
+	if (unset)
+		line_termination = '\n';
+	else
+		line_termination = 0;
+	return 0;
+}
+
+static int option_parse_whitespace(const struct option *opt,
+				   const char *arg, int unset)
+{
+	const char **whitespace_option = opt->value;
+
+	*whitespace_option = arg;
+	parse_whitespace_option(arg);
+	return 0;
+}
+
+static int option_parse_directory(const struct option *opt,
+				  const char *arg, int unset)
+{
+	root_len = strlen(arg);
+	if (root_len && arg[root_len - 1] != '/') {
+		char *new_root;
+		root = new_root = xmalloc(root_len + 2);
+		strcpy(new_root, arg);
+		strcpy(new_root + root_len++, "/");
+	} else
+		root = arg;
+	return 0;
+}
 
 int cmd_apply(int argc, const char **argv, const char *unused_prefix)
 {
 	int i;
-	int read_stdin = 1;
-	int options = 0;
 	int errs = 0;
 	int is_not_gitdir;
+	int binary;
+	int force_apply = 0;
 
 	const char *whitespace_option = NULL;
 
+	struct option builtin_apply_options[] = {
+		{ OPTION_CALLBACK, '-', NULL, &errs, NULL,
+			"read the patch from the standard input",
+			PARSE_OPT_NOARG, option_parse_stdin },
+		{ OPTION_CALLBACK, 0, "exclude", NULL, "path",
+			"don´t apply changes matching the given path",
+			0, option_parse_exclude },
+		{ OPTION_CALLBACK, 0, "include", NULL, "path",
+			"apply changes matching the given path",
+			0, option_parse_include },
+		{ OPTION_CALLBACK, 'p', NULL, NULL, "num",
+			"remove <num> leading slashes from traditional diff paths",
+			0, option_parse_p },
+		OPT_BOOLEAN(0, "no-add", &no_add,
+			"ignore additions made by the patch"),
+		OPT_BOOLEAN(0, "stat", &diffstat,
+			"instead of applying the patch, output diffstat for the input"),
+		OPT_BOOLEAN(0, "allow-binary-replacement", &binary,
+			"now no-op"),
+		OPT_BOOLEAN(0, "binary", &binary,
+			"now no-op"),
+		OPT_BOOLEAN(0, "numstat", &numstat,
+			"shows number of added and deleted lines in decimal notation"),
+		OPT_BOOLEAN(0, "summary", &summary,
+			"instead of applying the patch, output a summary for the input"),
+		OPT_BOOLEAN(0, "check", &check,
+			"instead of applying the patch, see if the patch is applicable"),
+		OPT_BOOLEAN(0, "index", &check_index,
+			"make sure the patch is applicable to the current index"),
+		OPT_BOOLEAN(0, "cached", &cached,
+			"apply a patch without touching the working tree"),
+		OPT_BOOLEAN(0, "apply", &force_apply,
+			"also apply the patch (use with --stat/--summary/--check)"),
+		OPT_STRING(0, "build-fake-ancestor", &fake_ancestor, "file",
+			"build a temporary index based on embedded index information"),
+		{ OPTION_CALLBACK, 'z', NULL, NULL, NULL,
+			"paths are separated with NUL character",
+			PARSE_OPT_NOARG, option_parse_z },
+		OPT_INTEGER('C', NULL, &p_context,
+				"ensure at least <n> lines of context match"),
+		{ OPTION_CALLBACK, 0, "whitespace", &whitespace_option, "action",
+			"detect new or modified lines that have whitespace errors",
+			0, option_parse_whitespace },
+		OPT_BOOLEAN('R', "reverse", &apply_in_reverse,
+			"apply the patch in reverse"),
+		OPT_BOOLEAN(0, "unidiff-zero", &unidiff_zero,
+			"don't expect at least one line of context"),
+		OPT_BOOLEAN(0, "reject", &apply_with_reject,
+			"leave the rejected hunks in corresponding *.rej files"),
+		OPT__VERBOSE(&apply_verbosely),
+		OPT_BIT(0, "inaccurate-eof", &options,
+			"tolerate incorrectly detected missing new-line at the end of file",
+			INACCURATE_EOF),
+		OPT_BIT(0, "recount", &options,
+			"do not trust the line counts in the hunk headers",
+			RECOUNT),
+		{ OPTION_CALLBACK, 0, "directory", NULL, "root",
+			"prepend <root> to all filenames",
+			0, option_parse_directory },
+		OPT_END()
+	};
+
 	prefix = setup_git_directory_gently(&is_not_gitdir);
 	prefix_length = prefix ? strlen(prefix) : 0;
 	git_config(git_apply_config, NULL);
 	if (apply_default_whitespace)
 		parse_whitespace_option(apply_default_whitespace);
 
-	for (i = 1; i < argc; i++) {
+	argc = parse_options(argc, argv, builtin_apply_options,
+			apply_usage, 0);
+	if (apply_with_reject)
+		apply = apply_verbosely = 1;
+	if (!force_apply && (diffstat || numstat || summary || check || fake_ancestor))
+		apply = 0;
+	if (check_index && is_not_gitdir)
+		die("--index outside a repository");
+	if (cached) {
+		if (is_not_gitdir)
+			die("--cached outside a repository");
+		check_index = 1;
+	}
+	for (i = 0; i < argc; i++) {
 		const char *arg = argv[i];
-		char *end;
 		int fd;
 
-		if (!strcmp(arg, "-")) {
-			errs |= apply_patch(0, "<stdin>", options);
-			read_stdin = 0;
-			continue;
-		}
-		if (!prefixcmp(arg, "--exclude=")) {
-			add_name_limit(arg + 10, 1);
-			continue;
-		}
-		if (!prefixcmp(arg, "--include=")) {
-			add_name_limit(arg + 10, 0);
-			has_include = 1;
-			continue;
-		}
-		if (!prefixcmp(arg, "-p")) {
-			p_value = atoi(arg + 2);
-			p_value_known = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--no-add")) {
-			no_add = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--stat")) {
-			apply = 0;
-			diffstat = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--allow-binary-replacement") ||
-		    !strcmp(arg, "--binary")) {
-			continue; /* now no-op */
-		}
-		if (!strcmp(arg, "--numstat")) {
-			apply = 0;
-			numstat = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--summary")) {
-			apply = 0;
-			summary = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--check")) {
-			apply = 0;
-			check = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--index")) {
-			if (is_not_gitdir)
-				die("--index outside a repository");
-			check_index = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--cached")) {
-			if (is_not_gitdir)
-				die("--cached outside a repository");
-			check_index = 1;
-			cached = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--apply")) {
-			apply = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--build-fake-ancestor")) {
-			apply = 0;
-			if (++i >= argc)
-				die ("need a filename");
-			fake_ancestor = argv[i];
-			continue;
-		}
-		if (!strcmp(arg, "-z")) {
-			line_termination = 0;
-			continue;
-		}
-		if (!prefixcmp(arg, "-C")) {
-			p_context = strtoul(arg + 2, &end, 0);
-			if (*end != '\0')
-				die("unrecognized context count '%s'", arg + 2);
-			continue;
-		}
-		if (!prefixcmp(arg, "--whitespace=")) {
-			whitespace_option = arg + 13;
-			parse_whitespace_option(arg + 13);
-			continue;
-		}
-		if (!strcmp(arg, "-R") || !strcmp(arg, "--reverse")) {
-			apply_in_reverse = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--unidiff-zero")) {
-			unidiff_zero = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--reject")) {
-			apply = apply_with_reject = apply_verbosely = 1;
-			continue;
-		}
-		if (!strcmp(arg, "-v") || !strcmp(arg, "--verbose")) {
-			apply_verbosely = 1;
-			continue;
-		}
-		if (!strcmp(arg, "--inaccurate-eof")) {
-			options |= INACCURATE_EOF;
-			continue;
-		}
-		if (!strcmp(arg, "--recount")) {
-			options |= RECOUNT;
-			continue;
-		}
-		if (!prefixcmp(arg, "--directory=")) {
-			arg += strlen("--directory=");
-			root_len = strlen(arg);
-			if (root_len && arg[root_len - 1] != '/') {
-				char *new_root;
-				root = new_root = xmalloc(root_len + 2);
-				strcpy(new_root, arg);
-				strcpy(new_root + root_len++, "/");
-			} else
-				root = arg;
-			continue;
-		}
 		if (0 < prefix_length)
 			arg = prefix_filename(prefix, prefix_length, arg);
 