 		report_tracking(new);
 }
 
+struct rev_list_args {
+	int argc;
+	int alloc;
+	const char **argv;
+};
+
+static void add_one_rev_list_arg(struct rev_list_args *args, const char *s)
+{
+	ALLOC_GROW(args->argv, args->argc + 1, args->alloc);
+	args->argv[args->argc++] = s;
+}
+
+static int add_one_ref_to_rev_list_arg(const char *refname,
+				       const unsigned char *sha1,
+				       int flags,
+				       void *cb_data)
+{
+	add_one_rev_list_arg(cb_data, refname);
+	return 0;
+}
+
+
+static void describe_one_orphan(struct strbuf *sb, struct commit *commit)
+{
+	struct pretty_print_context ctx = { 0 };
+
+	parse_commit(commit);
+	strbuf_addstr(sb, " - ");
+	pretty_print_commit(CMIT_FMT_ONELINE, commit, sb, &ctx);
+	strbuf_addch(sb, '\n');
+}
+
+#define ORPHAN_CUTOFF 4
+static void suggest_reattach(struct commit *commit, struct rev_info *revs)
+{
+	struct commit *c, *last = NULL;
+	struct strbuf sb = STRBUF_INIT;
+	int lost = 0;
+	while ((c = get_revision(revs)) != NULL) {
+		if (lost < ORPHAN_CUTOFF)
+			describe_one_orphan(&sb, c);
+		last = c;
+		lost++;
+	}
+	if (ORPHAN_CUTOFF < lost) {
+		int more = lost - ORPHAN_CUTOFF;
+		if (more == 1)
+			describe_one_orphan(&sb, last);
+		else
+			strbuf_addf(&sb, " ... and %d more.\n", more);
+	}
+
+	fprintf(stderr,
+		"Warning: you are leaving %d commit%s behind, "
+		"not connected to\n"
+		"any of your branches:\n\n"
+		"%s\n"
+		"If you want to keep them by creating a new branch, "
+		"this may be a good time\nto do so with:\n\n"
+		" git branch new_branch_name %s\n\n",
+		lost, ((1 < lost) ? "s" : ""),
+		sb.buf,
+		sha1_to_hex(commit->object.sha1));
+	strbuf_release(&sb);
+}
+
+/*
+ * We are about to leave commit that was at the tip of a detached
+ * HEAD.  If it is not reachable from any ref, this is the last chance
+ * for the user to do so without resorting to reflog.
+ */
+static void orphaned_commit_warning(struct commit *commit)
+{
+	struct rev_list_args args = { 0, 0, NULL };
+	struct rev_info revs;
+
+	add_one_rev_list_arg(&args, "(internal)");
+	add_one_rev_list_arg(&args, sha1_to_hex(commit->object.sha1));
+	add_one_rev_list_arg(&args, "--not");
+	for_each_ref(add_one_ref_to_rev_list_arg, &args);
+	add_one_rev_list_arg(&args, "--");
+	add_one_rev_list_arg(&args, NULL);
+
+	init_revisions(&revs, NULL);
+	if (setup_revisions(args.argc - 1, args.argv, &revs, NULL) != 1)
+		die("internal error: only -- alone should have been left");
+	if (prepare_revision_walk(&revs))
+		die("internal error in revision walk");
+	if (!(commit->object.flags & UNINTERESTING))
+		suggest_reattach(commit, &revs);
+	else
+		describe_detached_head("Previous HEAD position was", commit);
+}
+
 static int switch_branches(struct checkout_opts *opts, struct branch_info *new)
 {
 	int ret = 0;
