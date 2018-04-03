 	return 0;
 }
 
+/*
+ * Does it look like the resulting diff might be due to a rename?
+ *  - single entry
+ *  - not a valid previous file
+ */
+static inline int diff_might_be_rename(void)
+{
+	return diff_queued_diff.nr == 1 &&
+		!DIFF_FILE_VALID(diff_queued_diff.queue[0]->one);
+}
+
+static void try_to_follow_renames(struct tree_desc *t1, struct tree_desc *t2, const char *base, struct diff_options *opt)
+{
+	struct diff_options diff_opts;
+	const char *paths[2];
+	int i;
+
+	diff_setup(&diff_opts);
+	diff_opts.recursive = 1;
+	diff_opts.detect_rename = DIFF_DETECT_RENAME;
+	diff_opts.output_format = DIFF_FORMAT_NO_OUTPUT;
+	diff_opts.single_follow = opt->paths[0];
+	paths[0] = NULL;
+	diff_tree_setup_paths(paths, &diff_opts);
+	if (diff_setup_done(&diff_opts) < 0)
+		die("unable to set up diff options to follow renames");
+	diff_tree(t1, t2, base, &diff_opts);
+	diffcore_std(&diff_opts);
+
+	/* NOTE! Ignore the first diff! That was the old one! */
+	for (i = 1; i < diff_queued_diff.nr; i++) {
+		struct diff_filepair *p = diff_queued_diff.queue[i];
+
+		/*
+		 * Found a source? Not only do we use that for the new
+		 * diff_queued_diff, we also use that as the path in
+		 * the future!
+		 */
+		if ((p->status == 'R' || p->status == 'C') && !strcmp(p->two->path, opt->paths[0])) {
+			diff_queued_diff.queue[0] = p;
+			opt->paths[0] = xstrdup(p->one->path);
+			diff_tree_setup_paths(opt->paths, opt);
+			break;
+		}
+	}
+
+	/*
+	 * Then, ignore any but the first entry! It might be the old one,
+	 * or it might be the rename/copy we found
+	 */
+	diff_queued_diff.nr = 1;
+}
+
 int diff_tree_sha1(const unsigned char *old, const unsigned char *new, const char *base, struct diff_options *opt)
 {
 	void *tree1, *tree2;
