 	strbuf_release(&buf);
 	return dirty_submodule;
 }
+
+static int find_first_merges(struct object_array *result, const char *path,
+		struct commit *a, struct commit *b)
+{
+	int i, j;
+	struct object_array merges;
+	struct commit *commit;
+	int contains_another;
+
+	char merged_revision[42];
+	const char *rev_args[] = { "rev-list", "--merges", "--ancestry-path",
+				   "--all", merged_revision, NULL };
+	struct rev_info revs;
+	struct setup_revision_opt rev_opts;
+
+	memset(&merges, 0, sizeof(merges));
+	memset(result, 0, sizeof(struct object_array));
+	memset(&rev_opts, 0, sizeof(rev_opts));
+
+	/* get all revisions that merge commit a */
+	snprintf(merged_revision, sizeof(merged_revision), "^%s",
+			sha1_to_hex(a->object.sha1));
+	init_revisions(&revs, NULL);
+	rev_opts.submodule = path;
+	setup_revisions(sizeof(rev_args)/sizeof(char *)-1, rev_args, &revs, &rev_opts);
+
+	/* save all revisions from the above list that contain b */
+	if (prepare_revision_walk(&revs))
+		die("revision walk setup failed");
+	while ((commit = get_revision(&revs)) != NULL) {
+		struct object *o = &(commit->object);
+		if (in_merge_bases(b, &commit, 1))
+			add_object_array(o, NULL, &merges);
+	}
+
+	/* Now we've got all merges that contain a and b. Prune all
+	 * merges that contain another found merge and save them in
+	 * result.
+	 */
+	for (i = 0; i < merges.nr; i++) {
+		struct commit *m1 = (struct commit *) merges.objects[i].item;
+
+		contains_another = 0;
+		for (j = 0; j < merges.nr; j++) {
+			struct commit *m2 = (struct commit *) merges.objects[j].item;
+			if (i != j && in_merge_bases(m2, &m1, 1)) {
+				contains_another = 1;
+				break;
+			}
+		}
+
+		if (!contains_another)
+			add_object_array(merges.objects[i].item,
+					 merges.objects[i].name, result);
+	}
+
+	free(merges.objects);
+	return result->nr;
+}
+
+static void print_commit(struct commit *commit)
+{
+	struct strbuf sb = STRBUF_INIT;
+	struct pretty_print_context ctx = {0};
+	ctx.date_mode = DATE_NORMAL;
+	format_commit_message(commit, " %h: %m %s", &sb, &ctx);
+	fprintf(stderr, "%s\n", sb.buf);
+	strbuf_release(&sb);
+}
+
+#define MERGE_WARNING(path, msg) \
+	warning("Failed to merge submodule %s (%s)", path, msg);
+
+int merge_submodule(unsigned char result[20], const char *path,
+		    const unsigned char base[20], const unsigned char a[20],
+		    const unsigned char b[20])
+{
+	struct commit *commit_base, *commit_a, *commit_b;
+	int parent_count;
+	struct object_array merges;
+
+	int i;
+
+	/* store a in result in case we fail */
+	hashcpy(result, a);
+
+	/* we can not handle deletion conflicts */
+	if (is_null_sha1(base))
+		return 0;
+	if (is_null_sha1(a))
+		return 0;
+	if (is_null_sha1(b))
+		return 0;
+
+	if (add_submodule_odb(path)) {
+		MERGE_WARNING(path, "not checked out");
+		return 0;
+	}
+
+	if (!(commit_base = lookup_commit_reference(base)) ||
+	    !(commit_a = lookup_commit_reference(a)) ||
+	    !(commit_b = lookup_commit_reference(b))) {
+		MERGE_WARNING(path, "commits not present");
+		return 0;
+	}
+
+	/* check whether both changes are forward */
+	if (!in_merge_bases(commit_base, &commit_a, 1) ||
+	    !in_merge_bases(commit_base, &commit_b, 1)) {
+		MERGE_WARNING(path, "commits don't follow merge-base");
+		return 0;
+	}
+
+	/* Case #1: a is contained in b or vice versa */
+	if (in_merge_bases(commit_a, &commit_b, 1)) {
+		hashcpy(result, b);
+		return 1;
+	}
+	if (in_merge_bases(commit_b, &commit_a, 1)) {
+		hashcpy(result, a);
+		return 1;
+	}
+
+	/*
+	 * Case #2: There are one or more merges that contain a and b in
+	 * the submodule. If there is only one, then present it as a
+	 * suggestion to the user, but leave it marked unmerged so the
+	 * user needs to confirm the resolution.
+	 */
+
+	/* find commit which merges them */
+	parent_count = find_first_merges(&merges, path, commit_a, commit_b);
+	switch (parent_count) {
+	case 0:
+		MERGE_WARNING(path, "merge following commits not found");
+		break;
+
+	case 1:
+		MERGE_WARNING(path, "not fast-forward");
+		fprintf(stderr, "Found a possible merge resolution "
+				"for the submodule:\n");
+		print_commit((struct commit *) merges.objects[0].item);
+		fprintf(stderr,
+			"If this is correct simply add it to the index "
+			"for example\n"
+			"by using:\n\n"
+			"  git update-index --cacheinfo 160000 %s \"%s\"\n\n"
+			"which will accept this suggestion.\n",
+			sha1_to_hex(merges.objects[0].item->sha1), path);
+		break;
+
+	default:
+		MERGE_WARNING(path, "multiple merges found");
+		for (i = 0; i < merges.nr; i++)
+			print_commit((struct commit *) merges.objects[i].item);
+	}
+
+	free(merges.objects);
+	return 0;
+}
