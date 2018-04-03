 	if (entries < 0)
 		die("cache corrupted");
 
-	for (i = 1 ; i < argc; i++) {
-		const char *path = argv[i];
-		const char *p;
+	/*
+	 * Custom copy of parse_options() because we want to handle
+	 * filename arguments as they come.
+	 */
+	parse_options_start(&ctx, argc, argv, prefix,
+			    options, PARSE_OPT_STOP_AT_NON_OPTION);
+	while (ctx.argc) {
+		if (parseopt_state != PARSE_OPT_DONE)
+			parseopt_state = parse_options_step(&ctx, options,
+							    update_index_usage);
+		if (!ctx.argc)
+			break;
+		switch (parseopt_state) {
+		case PARSE_OPT_HELP:
+			exit(129);
+		case PARSE_OPT_NON_OPTION:
+		case PARSE_OPT_DONE:
+		{
+			const char *path = ctx.argv[0];
+			const char *p;
 
-		if (allow_options && *path == '-') {
-			if (!strcmp(path, "--")) {
-				allow_options = 0;
-				continue;
-			}
-			if (!strcmp(path, "-q")) {
-				refresh_flags |= REFRESH_QUIET;
-				continue;
-			}
-			if (!strcmp(path, "--ignore-submodules")) {
-				refresh_flags |= REFRESH_IGNORE_SUBMODULES;
-				continue;
-			}
-			if (!strcmp(path, "--add")) {
-				allow_add = 1;
-				continue;
-			}
-			if (!strcmp(path, "--replace")) {
-				allow_replace = 1;
-				continue;
-			}
-			if (!strcmp(path, "--remove")) {
-				allow_remove = 1;
-				continue;
-			}
-			if (!strcmp(path, "--unmerged")) {
-				refresh_flags |= REFRESH_UNMERGED;
-				continue;
-			}
-			if (!strcmp(path, "--refresh")) {
-				setup_work_tree();
-				has_errors |= refresh_cache(refresh_flags);
-				continue;
-			}
-			if (!strcmp(path, "--really-refresh")) {
-				setup_work_tree();
-				has_errors |= refresh_cache(REFRESH_REALLY | refresh_flags);
-				continue;
-			}
-			if (!strcmp(path, "--cacheinfo")) {
-				unsigned char sha1[20];
-				unsigned int mode;
-
-				if (i+3 >= argc)
-					die("git update-index: --cacheinfo <mode> <sha1> <path>");
-
-				if (strtoul_ui(argv[i+1], 8, &mode) ||
-				    get_sha1_hex(argv[i+2], sha1) ||
-				    add_cacheinfo(mode, sha1, argv[i+3], 0))
-					die("git update-index: --cacheinfo"
-					    " cannot add %s", argv[i+3]);
-				i += 3;
-				continue;
-			}
-			if (!strcmp(path, "--chmod=-x") ||
-			    !strcmp(path, "--chmod=+x")) {
-				if (argc <= i+1)
-					die("git update-index: %s <path>", path);
-				set_executable_bit = path[8];
-				continue;
-			}
-			if (!strcmp(path, "--assume-unchanged")) {
-				mark_valid_only = MARK_FLAG;
-				continue;
-			}
-			if (!strcmp(path, "--no-assume-unchanged")) {
-				mark_valid_only = UNMARK_FLAG;
-				continue;
-			}
-			if (!strcmp(path, "--no-skip-worktree")) {
-				mark_skip_worktree_only = UNMARK_FLAG;
-				continue;
-			}
-			if (!strcmp(path, "--skip-worktree")) {
-				mark_skip_worktree_only = MARK_FLAG;
-				continue;
-			}
-			if (!strcmp(path, "--info-only")) {
-				info_only = 1;
-				continue;
-			}
-			if (!strcmp(path, "--force-remove")) {
-				force_remove = 1;
-				continue;
-			}
-			if (!strcmp(path, "-z")) {
-				line_termination = 0;
-				continue;
-			}
-			if (!strcmp(path, "--stdin")) {
-				if (i != argc - 1)
-					die("--stdin must be at the end");
-				read_from_stdin = 1;
-				break;
-			}
-			if (!strcmp(path, "--index-info")) {
-				if (i != argc - 1)
-					die("--index-info must be at the end");
-				allow_add = allow_replace = allow_remove = 1;
-				read_index_info(line_termination);
-				break;
-			}
-			if (!strcmp(path, "--unresolve")) {
-				has_errors = do_unresolve(argc - i, argv + i,
-							  prefix, prefix_length);
-				if (has_errors)
-					active_cache_changed = 0;
-				goto finish;
-			}
-			if (!strcmp(path, "--again") || !strcmp(path, "-g")) {
-				setup_work_tree();
-				has_errors = do_reupdate(argc - i, argv + i,
-							 prefix, prefix_length);
-				if (has_errors)
-					active_cache_changed = 0;
-				goto finish;
-			}
-			if (!strcmp(path, "--ignore-missing")) {
-				refresh_flags |= REFRESH_IGNORE_MISSING;
-				continue;
-			}
-			if (!strcmp(path, "--verbose")) {
-				verbose = 1;
-				continue;
-			}
-			if (!strcmp(path, "--clear-resolve-undo")) {
-				resolve_undo_clear();
-				continue;
-			}
-			if (!strcmp(path, "-h") || !strcmp(path, "--help"))
-				usage(update_index_usage);
-			die("unknown option %s", path);
+			setup_work_tree();
+			p = prefix_path(prefix, prefix_length, path);
+			update_one(p, NULL, 0);
+			if (set_executable_bit)
+				chmod_path(set_executable_bit, p);
+			if (p < path || p > path + strlen(path))
+				free((char *)p);
+			ctx.argc--;
+			ctx.argv++;
+			break;
+		}
+		case PARSE_OPT_UNKNOWN:
+			if (ctx.argv[0][1] == '-')
+				error("unknown option '%s'", ctx.argv[0] + 2);
+			else
+				error("unknown switch '%c'", *ctx.opt);
+			usage_with_options(update_index_usage, options);
 		}
-		setup_work_tree();
-		p = prefix_path(prefix, prefix_length, path);
-		update_one(p, NULL, 0);
-		if (set_executable_bit)
-			chmod_path(set_executable_bit, p);
-		if (p < path || p > path + strlen(path))
-			free((char *)p);
 	}
+	argc = parse_options_end(&ctx);
+
 	if (read_from_stdin) {
 		struct strbuf buf = STRBUF_INIT, nbuf = STRBUF_INIT;
 
