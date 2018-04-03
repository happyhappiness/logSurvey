 	return 0;
 }
 
-static int submodule_needs_pushing(const char *path, const unsigned char sha1[20])
+static int check_has_commit(const unsigned char sha1[20], void *data)
 {
-	if (add_submodule_odb(path) || !lookup_commit_reference(sha1))
+	int *has_commit = data;
+
+	if (!lookup_commit_reference(sha1))
+		*has_commit = 0;
+
+	return 0;
+}
+
+static int submodule_has_commits(const char *path, struct sha1_array *commits)
+{
+	int has_commit = 1;
+
+	if (add_submodule_odb(path))
+		return 0;
+
+	sha1_array_for_each_unique(commits, check_has_commit, &has_commit);
+	return has_commit;
+}
+
+static int submodule_needs_pushing(const char *path, struct sha1_array *commits)
+{
+	if (!submodule_has_commits(path, commits))
 		return 0;
 
 	if (for_each_remote_ref_submodule(path, has_remote, NULL) > 0) {
 		struct child_process cp = CHILD_PROCESS_INIT;
-		const char *argv[] = {"rev-list", NULL, "--not", "--remotes", "-n", "1" , NULL};
 		struct strbuf buf = STRBUF_INIT;
 		int needs_pushing = 0;
 
-		argv[1] = sha1_to_hex(sha1);
-		cp.argv = argv;
+		argv_array_push(&cp.args, "rev-list");
+		sha1_array_for_each_unique(commits, append_sha1_to_argv, &cp.args);
+		argv_array_pushl(&cp.args, "--not", "--remotes", "-n", "1" , NULL);
+
 		prepare_submodule_repo_env(&cp.env_array);
 		cp.git_cmd = 1;
 		cp.no_stdin = 1;
 		cp.out = -1;
 		cp.dir = path;
 		if (start_command(&cp))
-			die("Could not run 'git rev-list %s --not --remotes -n 1' command in submodule %s",
-				sha1_to_hex(sha1), path);
+			die("Could not run 'git rev-list <commits> --not --remotes -n 1' command in submodule %s",
+					path);
 		if (strbuf_read(&buf, cp.out, 41))
 			needs_pushing = 1;
 		finish_command(&cp);
