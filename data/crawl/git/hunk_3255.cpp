 	return remoteheads;
 }
 
+static struct commit_list *collect_parents(struct commit *head_commit,
+					   int *head_subsumed,
+					   int argc, const char **argv)
+{
+	int i;
+	struct commit_list *remoteheads = NULL;
+	struct commit_list **remotes = &remoteheads;
+
+	if (head_commit)
+		remotes = &commit_list_insert(head_commit, remotes)->next;
+	for (i = 0; i < argc; i++) {
+		struct commit *commit = get_merge_parent(argv[i]);
+		if (!commit)
+			help_unknown_ref(argv[i], "merge",
+					 "not something we can merge");
+		remotes = &commit_list_insert(commit, remotes)->next;
+	}
+
+	return reduce_parents(head_commit, head_subsumed, remoteheads);
+}
+
 int cmd_merge(int argc, const char **argv, const char *prefix)
 {
 	unsigned char result_tree[20];