 static const char merge_base_usage[] =
 "git merge-base [--all] <commit-id> <commit-id>";
 
+static struct commit *get_commit_reference(const char *arg)
+{
+	unsigned char revkey[20];
+	struct commit *r;
+
+	if (get_sha1(arg, revkey))
+		die("Not a valid object name %s", arg);
+	r = lookup_commit_reference(revkey);
+	if (!r)
+		die("Not a valid commit name %s", arg);
+
+	return r;
+}
+
 int cmd_merge_base(int argc, const char **argv, const char *prefix)
 {
 	struct commit *rev1, *rev2;
-	unsigned char rev1key[20], rev2key[20];
 	int show_all = 0;
 
 	git_config(git_default_config, NULL);
