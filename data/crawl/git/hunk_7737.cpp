 		die("Branch is renamed, but update of config-file failed");
 }
 
+static int opt_parse_with_commit(const struct option *opt, const char *arg, int unset)
+{
+	unsigned char sha1[20];
+	struct commit *commit;
+
+	if (!arg)
+		return -1;
+	if (get_sha1(arg, sha1))
+		die("malformed object name %s", arg);
+	commit = lookup_commit_reference(sha1);
+	if (!commit)
+		die("no such commit %s", arg);
+	commit_list_insert(commit, opt->value);
+	return 0;
+}
+
 int cmd_branch(int argc, const char **argv, const char *prefix)
 {
 	int delete = 0, rename = 0, force_create = 0;
 	int verbose = 0, abbrev = DEFAULT_ABBREV, detached = 0;
 	int reflog = 0, track;
 	int kinds = REF_LOCAL_BRANCH;
+	struct commit_list *with_commit = NULL;
 
 	struct option options[] = {
 		OPT_GROUP("Generic options"),
