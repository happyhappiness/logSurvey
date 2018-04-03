 	return 0;
 }
 
-static void read_populate_opts(struct replay_opts **opts_ptr)
+static int read_populate_opts(struct replay_opts **opts)
 {
 	if (!file_exists(git_path_opts_file()))
-		return;
-	if (git_config_from_file(populate_opts_cb, git_path_opts_file(), *opts_ptr) < 0)
-		die(_("Malformed options sheet: %s"), git_path_opts_file());
+		return 0;
+	/*
+	 * The function git_parse_source(), called from git_config_from_file(),
+	 * may die() in case of a syntactically incorrect file. We do not care
+	 * about this case, though, because we wrote that file ourselves, so we
+	 * are pretty certain that it is syntactically correct.
+	 */
+	if (git_config_from_file(populate_opts_cb, git_path_opts_file(), *opts) < 0)
+		return error(_("Malformed options sheet: %s"),
+			git_path_opts_file());
+	return 0;
 }
 
 static int walk_revs_populate_todo(struct commit_list **todo_list,
