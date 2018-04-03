 	return clean_merge;
 }
 
+/*
+ * Per entry merge function for D/F conflicts, to be called only after
+ * all files below dir have been processed.  We do this because in the
+ * cases we can cleanly resolve D/F conflicts, process_entry() can clean
+ * out all the files below the directory for us.
+ */
+static int process_df_entry(struct merge_options *o,
+			 const char *path, struct stage_data *entry)
+{
+	int clean_merge = 1;
+	unsigned o_mode = entry->stages[1].mode;
+	unsigned a_mode = entry->stages[2].mode;
+	unsigned b_mode = entry->stages[3].mode;
+	unsigned char *o_sha = stage_sha(entry->stages[1].sha, o_mode);
+	unsigned char *a_sha = stage_sha(entry->stages[2].sha, a_mode);
+	unsigned char *b_sha = stage_sha(entry->stages[3].sha, b_mode);
+	const char *add_branch;
+	const char *other_branch;
+	unsigned mode;
+	const unsigned char *sha;
+	const char *conf;
+	struct stat st;
+
+	/* We currently only handle D->F cases */
+	assert((!o_sha && a_sha && !b_sha) ||
+	       (!o_sha && !a_sha && b_sha));
+
+	entry->processed = 1;
+
+	if (a_sha) {
+		add_branch = o->branch1;
+		other_branch = o->branch2;
+		mode = a_mode;
+		sha = a_sha;
+		conf = "file/directory";
+	} else {
+		add_branch = o->branch2;
+		other_branch = o->branch1;
+		mode = b_mode;
+		sha = b_sha;
+		conf = "directory/file";
+	}
+	if (lstat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
+		const char *new_path = unique_path(o, path, add_branch);
+		clean_merge = 0;
+		output(o, 1, "CONFLICT (%s): There is a directory with name %s in %s. "
+		       "Adding %s as %s",
+		       conf, path, other_branch, path, new_path);
+		remove_file(o, 0, path, 0);
+		update_file(o, 0, sha, mode, new_path);
+	} else {
+		output(o, 2, "Adding %s", path);
+		update_file(o, 1, sha, mode, path);
+	}
+
+	return clean_merge;
+}
+
 struct unpack_trees_error_msgs get_porcelain_error_msgs(void)
 {
 	struct unpack_trees_error_msgs msgs = {
