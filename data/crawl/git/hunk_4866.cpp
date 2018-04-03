 		die("git checkout: -f and -m are incompatible");
 
 	/*
-	 * case 1: git checkout <ref> -- [<paths>]
-	 *
-	 *   <ref> must be a valid tree, everything after the '--' must be
-	 *   a path.
-	 *
-	 * case 2: git checkout -- [<paths>]
-	 *
-	 *   everything after the '--' must be paths.
+	 * Extract branch name from command line arguments, so
+	 * all that is left is pathspecs.
 	 *
-	 * case 3: git checkout <something> [<paths>]
-	 *
-	 *   With no paths, if <something> is a commit, that is to
-	 *   switch to the branch or detach HEAD at it.  As a special case,
-	 *   if <something> is A...B (missing A or B means HEAD but you can
-	 *   omit at most one side), and if there is a unique merge base
-	 *   between A and B, A...B names that merge base.
-	 *
-	 *   With no paths, if <something> is _not_ a commit, no -t nor -b
-	 *   was given, and there is a tracking branch whose name is
-	 *   <something> in one and only one remote, then this is a short-hand
-	 *   to fork local <something> from that remote tracking branch.
+	 * Handle
 	 *
-	 *   Otherwise <something> shall not be ambiguous.
-	 *   - If it's *only* a reference, treat it like case (1).
-	 *   - If it's only a path, treat it like case (2).
-	 *   - else: fail.
+	 *  1) git checkout <tree> -- [<paths>]
+	 *  2) git checkout -- [<paths>]
+	 *  3) git checkout <something> [<paths>]
 	 *
+	 * including "last branch" syntax and DWIM-ery for names of
+	 * remote branches, erroring out for invalid or ambiguous cases.
 	 */
 	if (argc) {
-		if (!strcmp(argv[0], "--")) {       /* case (2) */
-			argv++;
-			argc--;
-			goto no_reference;
-		}
-
-		arg = argv[0];
-		has_dash_dash = (argc > 1) && !strcmp(argv[1], "--");
-
-		if (!strcmp(arg, "-"))
-			arg = "@{-1}";
-
-		if (get_sha1_mb(arg, rev)) {
-			if (has_dash_dash)          /* case (1) */
-				die("invalid reference: %s", arg);
-			if (!patch_mode &&
-			    dwim_new_local_branch &&
-			    opts.track == BRANCH_TRACK_UNSPECIFIED &&
-			    !opts.new_branch &&
-			    !check_filename(NULL, arg) &&
-			    argc == 1) {
-				const char *remote = unique_tracking_name(arg);
-				if (!remote || get_sha1(remote, rev))
-					goto no_reference;
-				opts.new_branch = arg;
-				arg = remote;
-				/* DWIMmed to create local branch */
-			}
-			else
-				goto no_reference;
-		}
-
-		/* we can't end up being in (2) anymore, eat the argument */
-		argv++;
-		argc--;
-
-		new.name = arg;
-		setup_branch_path(&new);
-
-		if (check_ref_format(new.path) == CHECK_REF_FORMAT_OK &&
-		    resolve_ref(new.path, branch_rev, 1, NULL))
-			hashcpy(rev, branch_rev);
-		else
-			new.path = NULL; /* not an existing branch */
-
-		if (!(new.commit = lookup_commit_reference_gently(rev, 1))) {
-			/* not a commit */
-			source_tree = parse_tree_indirect(rev);
-		} else {
-			parse_commit(new.commit);
-			source_tree = new.commit->tree;
-		}
-
-		if (!source_tree)                   /* case (1): want a tree */
-			die("reference is not a tree: %s", arg);
-		if (!has_dash_dash) {/* case (3 -> 1) */
-			/*
-			 * Do not complain the most common case
-			 *	git checkout branch
-			 * even if there happen to be a file called 'branch';
-			 * it would be extremely annoying.
-			 */
-			if (argc)
-				verify_non_filename(NULL, arg);
-		}
-		else {
-			argv++;
-			argc--;
-		}
+		int dwim_ok =
+			!patch_mode &&
+			dwim_new_local_branch &&
+			opts.track == BRANCH_TRACK_UNSPECIFIED &&
+			!opts.new_branch;
+		int n = parse_branchname_arg(argc, argv, dwim_ok,
+				&new, &source_tree, rev, &opts.new_branch);
+		argv += n;
+		argc -= n;
 	}
 
-no_reference:
-
 	if (opts.track == BRANCH_TRACK_UNSPECIFIED)
 		opts.track = git_branch_track;
 