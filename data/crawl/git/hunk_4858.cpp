 
 }
 
+static void write_merge_msg(void)
+{
+	int fd = open(git_path("MERGE_MSG"), O_WRONLY | O_CREAT, 0666);
+	if (fd < 0)
+		die_errno("Could not open '%s' for writing",
+			  git_path("MERGE_MSG"));
+	if (write_in_full(fd, merge_msg.buf, merge_msg.len) != merge_msg.len)
+		die_errno("Could not write to '%s'", git_path("MERGE_MSG"));
+	close(fd);
+}
+
+static void read_merge_msg(void)
+{
+	strbuf_reset(&merge_msg);
+	if (strbuf_read_file(&merge_msg, git_path("MERGE_MSG"), 0) < 0)
+		die_errno("Could not read from '%s'", git_path("MERGE_MSG"));
+}
+
+static void run_prepare_commit_msg(void)
+{
+	write_merge_msg();
+	run_hook(get_index_file(), "prepare-commit-msg",
+		 git_path("MERGE_MSG"), "merge", NULL, NULL);
+	read_merge_msg();
+}
+
 static int merge_trivial(void)
 {
 	unsigned char result_tree[20], result_commit[20];
