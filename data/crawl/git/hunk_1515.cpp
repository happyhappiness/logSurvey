 	strbuf_release(&sb);
 }
 
-void show_submodule_summary(FILE *f, const char *path,
+/* Helper function to display the submodule header line prior to the full
+ * summary output. If it can locate the submodule objects directory it will
+ * attempt to lookup both the left and right commits and put them into the
+ * left and right pointers.
+ */
+static void show_submodule_header(FILE *f, const char *path,
 		const char *line_prefix,
 		struct object_id *one, struct object_id *two,
 		unsigned dirty_submodule, const char *meta,
-		const char *del, const char *add, const char *reset)
+		const char *reset,
+		struct commit **left, struct commit **right,
+		struct commit_list **merge_bases)
 {
-	struct rev_info rev;
-	struct commit *left = NULL, *right = NULL;
 	const char *message = NULL;
 	struct strbuf sb = STRBUF_INIT;
 	int fast_forward = 0, fast_backward = 0;
 
-	if (is_null_oid(two))
-		message = "(submodule deleted)";
-	else if (add_submodule_odb(path))
-		message = "(not initialized)";
-	else if (is_null_oid(one))
-		message = "(new submodule)";
-	else if (!(left = lookup_commit_reference(one->hash)) ||
-		 !(right = lookup_commit_reference(two->hash)))
-		message = "(commits not present)";
-	else if (prepare_submodule_summary(&rev, path, left, right,
-					   &fast_forward, &fast_backward))
-		message = "(revision walker failed)";
-
 	if (dirty_submodule & DIRTY_SUBMODULE_UNTRACKED)
 		fprintf(f, "%sSubmodule %s contains untracked content\n",
 			line_prefix, path);
 	if (dirty_submodule & DIRTY_SUBMODULE_MODIFIED)
 		fprintf(f, "%sSubmodule %s contains modified content\n",
 			line_prefix, path);
 
+	if (is_null_oid(one))
+		message = "(new submodule)";
+	else if (is_null_oid(two))
+		message = "(submodule deleted)";
+
+	if (add_submodule_odb(path)) {
+		if (!message)
+			message = "(not initialized)";
+		goto output_header;
+	}
+
+	/*
+	 * Attempt to lookup the commit references, and determine if this is
+	 * a fast forward or fast backwards update.
+	 */
+	*left = lookup_commit_reference(one->hash);
+	*right = lookup_commit_reference(two->hash);
+
+	/*
+	 * Warn about missing commits in the submodule project, but only if
+	 * they aren't null.
+	 */
+	if ((!is_null_oid(one) && !*left) ||
+	     (!is_null_oid(two) && !*right))
+		message = "(commits not present)";
+
+	*merge_bases = get_merge_bases(*left, *right);
+	if (*merge_bases) {
+		if ((*merge_bases)->item == *left)
+			fast_forward = 1;
+		else if ((*merge_bases)->item == *right)
+			fast_backward = 1;
+	}
+
 	if (!oidcmp(one, two)) {
 		strbuf_release(&sb);
 		return;
 	}
 
+output_header:
 	strbuf_addf(&sb, "%s%sSubmodule %s %s..", line_prefix, meta, path,
 			find_unique_abbrev(one->hash, DEFAULT_ABBREV));
 	if (!fast_backward && !fast_forward)
