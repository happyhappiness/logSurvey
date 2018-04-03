 	return git_default_config(var, value, cb);
 }
 
-static void verify_working_tree_path(unsigned char *head_sha1, const char *path)
+static void verify_working_tree_path(struct commit *work_tree, const char *path)
 {
-	unsigned char blob_sha1[20];
-	unsigned mode;
+	struct commit_list *parents;
 
-	if (!resolve_ref_unsafe("HEAD", head_sha1, 1, NULL))
-		die("no such ref: HEAD");
-	if (get_tree_entry(head_sha1, path, blob_sha1, &mode))
-		die("no such path '%s' in HEAD", path);
-	if (sha1_object_info(blob_sha1, NULL) != OBJ_BLOB)
-		die("path '%s' in HEAD is not a blob", path);
+	for (parents = work_tree->parents; parents; parents = parents->next) {
+		const unsigned char *commit_sha1 = parents->item->object.sha1;
+		unsigned char blob_sha1[20];
+		unsigned mode;
+
+		if (!get_tree_entry(commit_sha1, path, blob_sha1, &mode) &&
+		    sha1_object_info(blob_sha1, NULL) == OBJ_BLOB)
+			return;
+	}
+	die("no such path '%s' in HEAD", path);
+}
+
+static struct commit_list **append_parent(struct commit_list **tail, const unsigned char *sha1)
+{
+	struct commit *parent;
+
+	parent = lookup_commit_reference(sha1);
+	if (!parent)
+		die("no such commit %s", sha1_to_hex(sha1));
+	return &commit_list_insert(parent, tail)->next;
+}
+
+static void append_merge_parents(struct commit_list **tail)
+{
+	int merge_head;
+	const char *merge_head_file = git_path("MERGE_HEAD");
+	struct strbuf line = STRBUF_INIT;
+
+	merge_head = open(merge_head_file, O_RDONLY);
+	if (merge_head < 0) {
+		if (errno == ENOENT)
+			return;
+		die("cannot open '%s' for reading", merge_head_file);
+	}
+
+	while (!strbuf_getwholeline_fd(&line, merge_head, '\n')) {
+		unsigned char sha1[20];
+		if (line.len < 40 || get_sha1_hex(line.buf, sha1))
+			die("unknown line in '%s': %s", merge_head_file, line.buf);
+		tail = append_parent(tail, sha1);
+	}
+	close(merge_head);
+	strbuf_release(&line);
 }
 
 /*
