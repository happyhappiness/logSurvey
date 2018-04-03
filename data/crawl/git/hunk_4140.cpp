 		st_stdin.st_mode == st_stdout.st_mode);
 }
 
+static struct commit_list *collect_parents(int argc, const char **argv)
+{
+	int i;
+	struct commit_list *remoteheads = NULL;
+	struct commit_list **remotes = &remoteheads;
+
+	for (i = 0; i < argc; i++) {
+		struct commit *commit = get_merge_parent(argv[i]);
+		if (!commit)
+			die(_("%s - not something we can merge"), argv[i]);
+		remotes = &commit_list_insert(commit, remotes)->next;
+	}
+	*remotes = NULL;
+	return remoteheads;
+}
 
 int cmd_merge(int argc, const char **argv, const char *prefix)
 {
