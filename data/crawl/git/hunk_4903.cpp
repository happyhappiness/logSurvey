 	return 0;
 }
 
+struct refresh_params {
+	unsigned int flags;
+	int *has_errors;
+};
+
+static int refresh(struct refresh_params *o, unsigned int flag)
+{
+	setup_work_tree();
+	*o->has_errors |= refresh_cache(o->flags | flag);
+	return 0;
+}
+
+static int refresh_callback(const struct option *opt,
+				const char *arg, int unset)
+{
+	return refresh(opt->value, 0);
+}
+
+static int really_refresh_callback(const struct option *opt,
+				const char *arg, int unset)
+{
+	return refresh(opt->value, REFRESH_REALLY);
+}
+
+static int chmod_callback(const struct option *opt,
+				const char *arg, int unset)
+{
+	char *flip = opt->value;
+	if ((arg[0] != '-' && arg[0] != '+') || arg[1] != 'x' || arg[2])
+		return error("option 'chmod' expects \"+x\" or \"-x\"");
+	*flip = arg[0];
+	return 0;
+}
+
+static int resolve_undo_clear_callback(const struct option *opt,
+				const char *arg, int unset)
+{
+	resolve_undo_clear();
+	return 0;
+}
+
+static int cacheinfo_callback(struct parse_opt_ctx_t *ctx,
+				const struct option *opt, int unset)
+{
+	unsigned char sha1[20];
+	unsigned int mode;
+
+	if (ctx->argc <= 3)
+		return error("option 'cacheinfo' expects three arguments");
+	if (strtoul_ui(*++ctx->argv, 8, &mode) ||
+	    get_sha1_hex(*++ctx->argv, sha1) ||
+	    add_cacheinfo(mode, sha1, *++ctx->argv, 0))
+		die("git update-index: --cacheinfo cannot add %s", *ctx->argv);
+	ctx->argc -= 3;
+	return 0;
+}
+
+static int stdin_cacheinfo_callback(struct parse_opt_ctx_t *ctx,
+			      const struct option *opt, int unset)
+{
+	int *line_termination = opt->value;
+
+	if (ctx->argc != 1)
+		return error("option '%s' must be the last argument", opt->long_name);
+	allow_add = allow_replace = allow_remove = 1;
+	read_index_info(*line_termination);
+	return 0;
+}
+
+static int stdin_callback(struct parse_opt_ctx_t *ctx,
+				const struct option *opt, int unset)
+{
+	int *read_from_stdin = opt->value;
+
+	if (ctx->argc != 1)
+		return error("option '%s' must be the last argument", opt->long_name);
+	*read_from_stdin = 1;
+	return 0;
+}
+
+static int unresolve_callback(struct parse_opt_ctx_t *ctx,
+				const struct option *opt, int flags)
+{
+	int *has_errors = opt->value;
+	const char *prefix = startup_info->prefix;
+
+	/* consume remaining arguments. */
+	*has_errors = do_unresolve(ctx->argc, ctx->argv,
+				prefix, prefix ? strlen(prefix) : 0);
+	if (*has_errors)
+		active_cache_changed = 0;
+
+	ctx->argv += ctx->argc - 1;
+	ctx->argc = 1;
+	return 0;
+}
+
+static int reupdate_callback(struct parse_opt_ctx_t *ctx,
+				const struct option *opt, int flags)
+{
+	int *has_errors = opt->value;
+	const char *prefix = startup_info->prefix;
+
+	/* consume remaining arguments. */
+	setup_work_tree();
+	*has_errors = do_reupdate(ctx->argc, ctx->argv,
+				prefix, prefix ? strlen(prefix) : 0);
+	if (*has_errors)
+		active_cache_changed = 0;
+
+	ctx->argv += ctx->argc - 1;
+	ctx->argc = 1;
+	return 0;
+}
+
 int cmd_update_index(int argc, const char **argv, const char *prefix)
 {
-	int i, newfd, entries, has_errors = 0, line_termination = '\n';
-	int allow_options = 1;
+	int newfd, entries, has_errors = 0, line_termination = '\n';
 	int read_from_stdin = 0;
 	int prefix_length = prefix ? strlen(prefix) : 0;
 	char set_executable_bit = 0;
-	unsigned int refresh_flags = 0;
+	struct refresh_params refresh_args = {0, &has_errors};
 	int lock_error = 0;
 	struct lock_file *lock_file;
+	struct parse_opt_ctx_t ctx;
+	int parseopt_state = PARSE_OPT_UNKNOWN;
+	struct option options[] = {
+		OPT_BIT('q', NULL, &refresh_args.flags,
+			"continue refresh even when index needs update",
+			REFRESH_QUIET),
+		OPT_BIT(0, "ignore-submodules", &refresh_args.flags,
+			"refresh: ignore submodules",
+			REFRESH_IGNORE_SUBMODULES),
+		OPT_SET_INT(0, "add", &allow_add,
+			"do not ignore new files", 1),
+		OPT_SET_INT(0, "replace", &allow_replace,
+			"let files replace directories and vice-versa", 1),
+		OPT_SET_INT(0, "remove", &allow_remove,
+			"notice files missing from worktree", 1),
+		OPT_BIT(0, "unmerged", &refresh_args.flags,
+			"refresh even if index contains unmerged entries",
+			REFRESH_UNMERGED),
+		{OPTION_CALLBACK, 0, "refresh", &refresh_args, NULL,
+			"refresh stat information",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG,
+			refresh_callback},
+		{OPTION_CALLBACK, 0, "really-refresh", &refresh_args, NULL,
+			"like --refresh, but ignore assume-unchanged setting",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG,
+			really_refresh_callback},
+		{OPTION_LOWLEVEL_CALLBACK, 0, "cacheinfo", NULL,
+			"<mode> <object> <path>",
+			"add the specified entry to the index",
+			PARSE_OPT_NOARG |	/* disallow --cacheinfo=<mode> form */
+			PARSE_OPT_NONEG | PARSE_OPT_LITERAL_ARGHELP,
+			(parse_opt_cb *) cacheinfo_callback},
+		{OPTION_CALLBACK, 0, "chmod", &set_executable_bit, "(+/-)x",
+			"override the executable bit of the listed files",
+			PARSE_OPT_NONEG | PARSE_OPT_LITERAL_ARGHELP,
+			chmod_callback},
+		{OPTION_SET_INT, 0, "assume-unchanged", &mark_valid_only, NULL,
+			"mark files as \"not changing\"",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL, MARK_FLAG},
+		{OPTION_SET_INT, 0, "no-assume-unchanged", &mark_valid_only, NULL,
+			"clear assumed-unchanged bit",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL, UNMARK_FLAG},
+		{OPTION_SET_INT, 0, "skip-worktree", &mark_skip_worktree_only, NULL,
+			"mark files as \"index-only\"",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL, MARK_FLAG},
+		{OPTION_SET_INT, 0, "no-skip-worktree", &mark_skip_worktree_only, NULL,
+			"clear skip-worktree bit",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL, UNMARK_FLAG},
+		OPT_SET_INT(0, "info-only", &info_only,
+			"add to index only; do not add content to object database", 1),
+		OPT_SET_INT(0, "force-remove", &force_remove,
+			"remove named paths even if present in worktree", 1),
+		OPT_SET_INT('z', NULL, &line_termination,
+			"with --stdin: input lines are terminated by null bytes", '\0'),
+		{OPTION_LOWLEVEL_CALLBACK, 0, "stdin", &read_from_stdin, NULL,
+			"read list of paths to be updated from standard input",
+			PARSE_OPT_NONEG | PARSE_OPT_NOARG,
+			(parse_opt_cb *) stdin_callback},
+		{OPTION_LOWLEVEL_CALLBACK, 0, "index-info", &line_termination, NULL,
+			"add entries from standard input to the index",
+			PARSE_OPT_NONEG | PARSE_OPT_NOARG,
+			(parse_opt_cb *) stdin_cacheinfo_callback},
+		{OPTION_LOWLEVEL_CALLBACK, 0, "unresolve", &has_errors, NULL,
+			"repopulate stages #2 and #3 for the listed paths",
+			PARSE_OPT_NONEG | PARSE_OPT_NOARG,
+			(parse_opt_cb *) unresolve_callback},
+		{OPTION_LOWLEVEL_CALLBACK, 'g', "again", &has_errors, NULL,
+			"only update entries that differ from HEAD",
+			PARSE_OPT_NONEG | PARSE_OPT_NOARG,
+			(parse_opt_cb *) reupdate_callback},
+		OPT_BIT(0, "ignore-missing", &refresh_args.flags,
+			"ignore files missing from worktree",
+			REFRESH_IGNORE_MISSING),
+		OPT_SET_INT(0, "verbose", &verbose,
+			"report actions to standard output", 1),
+		{OPTION_CALLBACK, 0, "clear-resolve-undo", NULL, NULL,
+			"(for porcelains) forget saved unresolved conflicts",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG,
+			resolve_undo_clear_callback},
+		OPT_END()
+	};
 
 	git_config(git_default_config, NULL);
 
