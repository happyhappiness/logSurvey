 	strbuf_release(&bname);
 }
 
+static void parse_branch_merge_options(char *bmo)
+{
+	const char **argv;
+	int argc;
+
+	if (!bmo)
+		return;
+	argc = split_cmdline(bmo, &argv);
+	if (argc < 0)
+		die("Bad branch.%s.mergeoptions string", branch);
+	argv = xrealloc(argv, sizeof(*argv) * (argc + 2));
+	memmove(argv + 1, argv, sizeof(*argv) * (argc + 1));
+	argc++;
+	argv[0] = "branch.*.mergeoptions";
+	parse_options(argc, argv, NULL, builtin_merge_options,
+		      builtin_merge_usage, 0);
+	free(argv);
+}
+
 static int git_merge_config(const char *k, const char *v, void *cb)
 {
 	if (branch && !prefixcmp(k, "branch.") &&
 		!prefixcmp(k + 7, branch) &&
 		!strcmp(k + 7 + strlen(branch), ".mergeoptions")) {
-		const char **argv;
-		int argc;
-		char *buf;
-
-		buf = xstrdup(v);
-		argc = split_cmdline(buf, &argv);
-		if (argc < 0)
-			die("Bad branch.%s.mergeoptions string", branch);
-		argv = xrealloc(argv, sizeof(*argv) * (argc + 2));
-		memmove(argv + 1, argv, sizeof(*argv) * (argc + 1));
-		argc++;
-		parse_options(argc, argv, NULL, builtin_merge_options,
-			      builtin_merge_usage, 0);
-		free(buf);
+		free(branch_mergeoptions);
+		branch_mergeoptions = xstrdup(v);
+		return 0;
 	}
 
 	if (!strcmp(k, "merge.diffstat") || !strcmp(k, "merge.stat"))
