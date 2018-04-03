 	argc = parse_options(argc, argv, prefix, options, checkout_usage,
 			     PARSE_OPT_KEEP_DASHDASH);
 
-	/* we can assume from now on new_branch = !new_branch_force */
-	if (opts.new_branch && opts.new_branch_force)
-		die(_("-B cannot be used with -b"));
+	if (conflict_style) {
+		opts.merge = 1; /* implied */
+		git_xmerge_config("merge.conflictstyle", conflict_style, NULL);
+	}
 
-	/* copy -B over to -b, so that we can just check the latter */
+	if ((!!opts.new_branch + !!opts.new_branch_force + !!opts.new_orphan_branch) > 1)
+		die(_("-b, -B and --orphan are mutually exclusive"));
+
+	/*
+	 * From here on, new_branch will contain the branch to be checked out,
+	 * and new_branch_force and new_orphan_branch will tell us which one of
+	 * -b/-B/--orphan is being used.
+	 */
 	if (opts.new_branch_force)
 		opts.new_branch = opts.new_branch_force;
 
-	if (opts.patch_mode && (opts.track > 0 || opts.new_branch
-			   || opts.new_branch_log || opts.merge || opts.force
-			   || opts.force_detach))
-		die (_("--patch is incompatible with all other options"));
-
-	if (opts.force_detach && (opts.new_branch || opts.new_orphan_branch))
-		die(_("--detach cannot be used with -b/-B/--orphan"));
-	if (opts.force_detach && 0 < opts.track)
-		die(_("--detach cannot be used with -t"));
+	if (opts.new_orphan_branch)
+		opts.new_branch = opts.new_orphan_branch;
 
-	/* --track without -b should DWIM */
-	if (0 < opts.track && !opts.new_branch) {
+	/* --track without -b/-B/--orphan should DWIM */
+	if (opts.track != BRANCH_TRACK_UNSPECIFIED && !opts.new_branch) {
 		const char *argv0 = argv[0];
 		if (!argc || !strcmp(argv0, "--"))
 			die (_("--track needs a branch name"));
