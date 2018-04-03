 	return retval;
 }
 
+static int merge_abort(struct notes_merge_options *o)
+{
+	int ret = 0;
+
+	/*
+	 * Remove .git/NOTES_MERGE_PARTIAL and .git/NOTES_MERGE_REF, and call
+	 * notes_merge_abort() to remove .git/NOTES_MERGE_WORKTREE.
+	 */
+
+	if (delete_ref("NOTES_MERGE_PARTIAL", NULL, 0))
+		ret += error("Failed to delete ref NOTES_MERGE_PARTIAL");
+	if (delete_ref("NOTES_MERGE_REF", NULL, REF_NODEREF))
+		ret += error("Failed to delete ref NOTES_MERGE_REF");
+	if (notes_merge_abort(o))
+		ret += error("Failed to remove 'git notes merge' worktree");
+	return ret;
+}
+
+static int merge_commit(struct notes_merge_options *o)
+{
+	struct strbuf msg = STRBUF_INIT;
+	unsigned char sha1[20];
+	struct notes_tree *t;
+	struct commit *partial;
+	struct pretty_print_context pretty_ctx;
+
+	/*
+	 * Read partial merge result from .git/NOTES_MERGE_PARTIAL,
+	 * and target notes ref from .git/NOTES_MERGE_REF.
+	 */
+
+	if (get_sha1("NOTES_MERGE_PARTIAL", sha1))
+		die("Failed to read ref NOTES_MERGE_PARTIAL");
+	else if (!(partial = lookup_commit_reference(sha1)))
+		die("Could not find commit from NOTES_MERGE_PARTIAL.");
+	else if (parse_commit(partial))
+		die("Could not parse commit from NOTES_MERGE_PARTIAL.");
+
+	t = xcalloc(1, sizeof(struct notes_tree));
+	init_notes(t, "NOTES_MERGE_PARTIAL", combine_notes_overwrite, 0);
+
+	o->local_ref = resolve_ref("NOTES_MERGE_REF", sha1, 0, 0);
+	if (!o->local_ref)
+		die("Failed to resolve NOTES_MERGE_REF");
+
+	if (notes_merge_commit(o, t, partial, sha1))
+		die("Failed to finalize notes merge");
+
+	/* Reuse existing commit message in reflog message */
+	memset(&pretty_ctx, 0, sizeof(pretty_ctx));
+	format_commit_message(partial, "%s", &msg, &pretty_ctx);
+	strbuf_trim(&msg);
+	strbuf_insert(&msg, 0, "notes: ", 7);
+	update_ref(msg.buf, o->local_ref, sha1, NULL, 0, DIE_ON_ERR);
+
+	free_notes(t);
+	strbuf_release(&msg);
+	return merge_abort(o);
+}
+
 static int merge(int argc, const char **argv, const char *prefix)
 {
 	struct strbuf remote_ref = STRBUF_INIT, msg = STRBUF_INIT;
 	unsigned char result_sha1[20];
 	struct notes_tree *t;
 	struct notes_merge_options o;
+	int do_merge = 0, do_commit = 0, do_abort = 0;
 	int verbosity = 0, result;
 	const char *strategy = NULL;
 	struct option options[] = {
+		OPT_GROUP("General options"),
 		OPT__VERBOSITY(&verbosity),
+		OPT_GROUP("Merge options"),
 		OPT_STRING('s', "strategy", &strategy, "strategy",
 			   "resolve notes conflicts using the given "
 			   "strategy (manual/ours/theirs/union)"),
+		OPT_GROUP("Committing unmerged notes"),
+		{ OPTION_BOOLEAN, 0, "commit", &do_commit, NULL,
+			"finalize notes merge by committing unmerged notes",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG },
+		OPT_GROUP("Aborting notes merge resolution"),
+		{ OPTION_BOOLEAN, 0, "abort", &do_abort, NULL,
+			"abort notes merge",
+			PARSE_OPT_NOARG | PARSE_OPT_NONEG },
 		OPT_END()
 	};
 
 	argc = parse_options(argc, argv, prefix, options,
 			     git_notes_merge_usage, 0);
 
-	if (argc != 1) {
+	if (strategy || do_commit + do_abort == 0)
+		do_merge = 1;
+	if (do_merge + do_commit + do_abort != 1) {
+		error("cannot mix --commit, --abort or -s/--strategy");
+		usage_with_options(git_notes_merge_usage, options);
+	}
+
+	if (do_merge && argc != 1) {
 		error("Must specify a notes ref to merge");
 		usage_with_options(git_notes_merge_usage, options);
+	} else if (!do_merge && argc) {
+		error("too many parameters");
+		usage_with_options(git_notes_merge_usage, options);
 	}
 
 	init_notes_merge_options(&o);
 	o.verbosity = verbosity + NOTES_MERGE_VERBOSITY_DEFAULT;
 
+	if (do_abort)
+		return merge_abort(&o);
+	if (do_commit)
+		return merge_commit(&o);
+
 	o.local_ref = default_notes_ref();
 	strbuf_addstr(&remote_ref, argv[0]);
 	expand_notes_ref(&remote_ref);
