 
 	argc = parse_options(argc, argv, options, checkout_usage,
 			     PARSE_OPT_KEEP_DASHDASH);
+
+	if (!opts.new_branch && (opts.track != git_branch_track))
+		die("git checkout: --track and --no-track require -b");
+
+	if (opts.force && opts.merge)
+		die("git checkout: -f and -m are incompatible");
+
+	/*
+	 * case 1: git checkout <ref> -- [<paths>]
+	 *
+	 *   <ref> must be a valid tree, everything after the '--' must be
+	 *   a path.
+	 *
+	 * case 2: git checkout -- [<paths>]
+	 *
+	 *   everything after the '--' must be paths.
+	 *
+	 * case 3: git checkout <something> [<paths>]
+	 *
+	 *   With no paths, if <something> is a commit, that is to
+	 *   switch to the branch or detach HEAD at it.
+	 *
+	 *   Otherwise <something> shall not be ambiguous.
+	 *   - If it's *only* a reference, treat it like case (1).
+	 *   - If it's only a path, treat it like case (2).
+	 *   - else: fail.
+	 *
+	 */
 	if (argc) {
+		if (!strcmp(argv[0], "--")) {       /* case (2) */
+			argv++;
+			argc--;
+			goto no_reference;
+		}
+
 		arg = argv[0];
-		if (get_sha1(arg, rev))
-			;
-		else if ((new.commit = lookup_commit_reference_gently(rev, 1))) {
+		has_dash_dash = (argc > 1) && !strcmp(argv[1], "--");
+
+		if (get_sha1(arg, rev)) {
+			if (has_dash_dash)          /* case (1) */
+				die("invalid reference: %s", arg);
+			goto no_reference;          /* case (3 -> 2) */
+		}
+
+		/* we can't end up being in (2) anymore, eat the argument */
+		argv++;
+		argc--;
+
+		if ((new.commit = lookup_commit_reference_gently(rev, 1))) {
 			new.name = arg;
 			setup_branch_path(&new);
 			if (resolve_ref(new.path, rev, 1, NULL))
