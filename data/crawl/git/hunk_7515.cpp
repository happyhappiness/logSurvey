 	return run_command(&hook);
 }
 
+static int is_a_merge(const unsigned char *sha1)
+{
+	struct commit *commit = lookup_commit(sha1);
+	if (!commit || parse_commit(commit))
+		die("could not parse HEAD commit");
+	return !!(commit->parents && commit->parents->next);
+}
+
 static const char sign_off_header[] = "Signed-off-by: ";
 
-static int prepare_log_message(const char *index_file, const char *prefix)
+static int prepare_to_commit(const char *index_file, const char *prefix)
 {
 	struct stat statbuf;
 	int commitable, saved_color_setting;
 	struct strbuf sb;
 	char *buffer;
 	FILE *fp;
 
+	if (!no_verify && run_hook(index_file, "pre-commit", NULL))
+		return 0;
+
 	strbuf_init(&sb, 0);
 	if (message.len) {
 		strbuf_addbuf(&sb, &message);
