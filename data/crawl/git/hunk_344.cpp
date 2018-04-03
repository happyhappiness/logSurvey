 	git_config(submodule_config, NULL);
 }
 
-void gitmodules_config(void)
-{
-	const char *work_tree = get_git_work_tree();
-	if (work_tree) {
-		struct strbuf gitmodules_path = STRBUF_INIT;
-		strbuf_addstr(&gitmodules_path, work_tree);
-		strbuf_addstr(&gitmodules_path, "/" GITMODULES_FILE);
-		if (read_cache() < 0)
-			die("index file corrupt");
-
-		if (!is_gitmodules_unmerged(&the_index))
-			git_config_from_file(git_modules_config,
-				gitmodules_path.buf, NULL);
-		strbuf_release(&gitmodules_path);
-	}
-}
-
 static int gitmodules_cb(const char *var, const char *value, void *data)
 {
 	struct repository *repo = data;
