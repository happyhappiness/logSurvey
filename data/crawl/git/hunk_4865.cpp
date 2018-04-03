 	return NULL;
 }
 
+static int parse_branchname_arg(int argc, const char **argv,
+				int dwim_new_local_branch_ok,
+				struct branch_info *new,
+				struct tree **source_tree,
+				unsigned char rev[20],
+				const char **new_branch)
+{
+	int argcount = 0;
+	unsigned char branch_rev[20];
+	const char *arg;
+	int has_dash_dash;
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
+	 *   switch to the branch or detach HEAD at it.  As a special case,
+	 *   if <something> is A...B (missing A or B means HEAD but you can
+	 *   omit at most one side), and if there is a unique merge base
+	 *   between A and B, A...B names that merge base.
+	 *
+	 *   With no paths, if <something> is _not_ a commit, no -t nor -b
+	 *   was given, and there is a tracking branch whose name is
+	 *   <something> in one and only one remote, then this is a short-hand
+	 *   to fork local <something> from that remote tracking branch.
+	 *
+	 *   Otherwise <something> shall not be ambiguous.
+	 *   - If it's *only* a reference, treat it like case (1).
+	 *   - If it's only a path, treat it like case (2).
+	 *   - else: fail.
+	 *
+	 */
+	if (!argc)
+		return 0;
+
+	if (!strcmp(argv[0], "--"))	/* case (2) */
+		return 1;
+
+	arg = argv[0];
+	has_dash_dash = (argc > 1) && !strcmp(argv[1], "--");
+
+	if (!strcmp(arg, "-"))
+		arg = "@{-1}";
+
+	if (get_sha1_mb(arg, rev)) {
+		if (has_dash_dash)          /* case (1) */
+			die("invalid reference: %s", arg);
+		if (dwim_new_local_branch_ok &&
+		    !check_filename(NULL, arg) &&
+		    argc == 1) {
+			const char *remote = unique_tracking_name(arg);
+			if (!remote || get_sha1(remote, rev))
+				return argcount;
+			*new_branch = arg;
+			arg = remote;
+			/* DWIMmed to create local branch */
+		} else {
+			return argcount;
+		}
+	}
+
+	/* we can't end up being in (2) anymore, eat the argument */
+	argcount++;
+	argv++;
+	argc--;
+
+	new->name = arg;
+	setup_branch_path(new);
+
+	if (check_ref_format(new->path) == CHECK_REF_FORMAT_OK &&
+	    resolve_ref(new->path, branch_rev, 1, NULL))
+		hashcpy(rev, branch_rev);
+	else
+		new->path = NULL; /* not an existing branch */
+
+	new->commit = lookup_commit_reference_gently(rev, 1);
+	if (!new->commit) {
+		/* not a commit */
+		*source_tree = parse_tree_indirect(rev);
+	} else {
+		parse_commit(new->commit);
+		*source_tree = new->commit->tree;
+	}
+
+	if (!*source_tree)                   /* case (1): want a tree */
+		die("reference is not a tree: %s", arg);
+	if (!has_dash_dash) {/* case (3 -> 1) */
+		/*
+		 * Do not complain the most common case
+		 *	git checkout branch
+		 * even if there happen to be a file called 'branch';
+		 * it would be extremely annoying.
+		 */
+		if (argc)
+			verify_non_filename(NULL, arg);
+	} else {
+		argcount++;
+		argv++;
+		argc--;
+	}
+
+	return argcount;
+}
+
 int cmd_checkout(int argc, const char **argv, const char *prefix)
 {
 	struct checkout_opts opts;
-	unsigned char rev[20], branch_rev[20];
-	const char *arg;
+	unsigned char rev[20];
 	struct branch_info new;
 	struct tree *source_tree = NULL;
 	char *conflict_style = NULL;
