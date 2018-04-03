 
 int cmd_shortlog(int argc, const char **argv, const char *prefix)
 {
-	struct shortlog log;
-	struct rev_info rev;
+	static struct shortlog log;
+	static struct rev_info rev;
 	int nongit;
 
+	static const struct option options[] = {
+		OPT_BOOLEAN('n', "numbered", &log.sort_by_number,
+			    "sort output according to the number of commits per author"),
+		OPT_BOOLEAN('s', "summary", &log.summary,
+			    "Suppress commit descriptions, only provides commit count"),
+		OPT_BOOLEAN('e', "email", &log.email,
+			    "Show the email address of each author"),
+		{ OPTION_CALLBACK, 'w', NULL, &log, "w[,i1[,i2]]",
+			"Linewrap output", PARSE_OPT_OPTARG, &parse_wrap_args },
+		OPT_END(),
+	};
+
+	struct parse_opt_ctx_t ctx;
+
 	prefix = setup_git_directory_gently(&nongit);
 	shortlog_init(&log);
-
-	/* since -n is a shadowed rev argument, parse our args first */
-	while (argc > 1) {
-		if (!strcmp(argv[1], "-n") || !strcmp(argv[1], "--numbered"))
-			log.sort_by_number = 1;
-		else if (!strcmp(argv[1], "-s") ||
-				!strcmp(argv[1], "--summary"))
-			log.summary = 1;
-		else if (!strcmp(argv[1], "-e") ||
-			 !strcmp(argv[1], "--email"))
-			log.email = 1;
-		else if (!prefixcmp(argv[1], "-w")) {
-			log.wrap_lines = 1;
-			parse_wrap_args(argv[1], &log.in1, &log.in2, &log.wrap);
+	init_revisions(&rev, prefix);
+	parse_options_start(&ctx, argc, argv, PARSE_OPT_KEEP_DASHDASH |
+			    PARSE_OPT_KEEP_ARGV0);
+
+	for (;;) {
+		int n;
+		switch (parse_options_step(&ctx, options, shortlog_usage)) {
+		case PARSE_OPT_HELP:
+			exit(129);
+		case PARSE_OPT_DONE:
+			goto parse_done;
 		}
-		else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
-			usage(shortlog_usage);
-		else
-			break;
-		argv++;
-		argc--;
+		n = handle_revision_opt(&rev, ctx.argc, ctx.argv,
+					&ctx.cpidx, ctx.out);
+		if (n <= 0) {
+			error("unknown option `%s'", ctx.argv[0]);
+			usage_with_options(shortlog_usage, options);
+		}
+		ctx.argv += n;
+		ctx.argc -= n;
+	}
+parse_done:
+	argc = parse_options_end(&ctx);
+
+	if (setup_revisions(argc, argv, &rev, NULL) != 1) {
+		error("unrecognized argument: %s", argv[1]);
+		usage_with_options(shortlog_usage, options);
 	}
-	init_revisions(&rev, prefix);
-	argc = setup_revisions(argc, argv, &rev, NULL);
-	if (argc > 1)
-		die ("unrecognized argument: %s", argv[1]);
 
 	/* assume HEAD if from a tty */
 	if (!nongit && !rev.pending.nr && isatty(0))