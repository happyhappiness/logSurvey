 	}
 }
 
-/*
- * Compile an argv_array with all of the options supported by --recurse_submodules
- */
-static void compile_submodule_options(const char **argv,
-				      const struct dir_struct *dir,
-				      int show_tag)
-{
-	if (line_terminator == '\0')
-		argv_array_push(&submodule_options, "-z");
-	if (show_tag)
-		argv_array_push(&submodule_options, "-t");
-	if (show_valid_bit)
-		argv_array_push(&submodule_options, "-v");
-	if (show_cached)
-		argv_array_push(&submodule_options, "--cached");
-	if (show_eol)
-		argv_array_push(&submodule_options, "--eol");
-	if (debug_mode)
-		argv_array_push(&submodule_options, "--debug");
-
-	/* Add Pathspecs */
-	argv_array_push(&submodule_options, "--");
-	for (; *argv; argv++)
-		argv_array_push(&submodule_options, *argv);
-}
+static void show_files(struct repository *repo, struct dir_struct *dir);
 
-/**
- * Recursively call ls-files on a submodule
- */
-static void show_gitlink(const struct cache_entry *ce)
+static void show_submodule(struct repository *superproject,
+			   struct dir_struct *dir, const char *path)
 {
-	struct child_process cp = CHILD_PROCESS_INIT;
-	int status;
-	char *dir;
-
-	prepare_submodule_repo_env(&cp.env_array);
-	argv_array_push(&cp.env_array, GIT_DIR_ENVIRONMENT);
-
-	if (prefix_len)
-		argv_array_pushf(&cp.env_array, "%s=%s",
-				 GIT_TOPLEVEL_PREFIX_ENVIRONMENT,
-				 prefix);
-	argv_array_pushf(&cp.args, "--super-prefix=%s%s/",
-			 super_prefix ? super_prefix : "",
-			 ce->name);
-	argv_array_push(&cp.args, "ls-files");
-	argv_array_push(&cp.args, "--recurse-submodules");
-
-	/* add supported options */
-	argv_array_pushv(&cp.args, submodule_options.argv);
-
-	cp.git_cmd = 1;
-	dir = mkpathdup("%s/%s", get_git_work_tree(), ce->name);
-	cp.dir = dir;
-	status = run_command(&cp);
-	free(dir);
-	if (status)
-		exit(status);
+	struct repository submodule;
+
+	if (repo_submodule_init(&submodule, superproject, path))
+		return;
+
+	if (repo_read_index(&submodule) < 0)
+		die("index file corrupt");
+
+	repo_read_gitmodules(&submodule);
+
+	show_files(&submodule, dir);
+
+	repo_clear(&submodule);
 }
 
-static void show_ce_entry(const struct index_state *istate,
-			  const char *tag, const struct cache_entry *ce)
+static void show_ce(struct repository *repo, struct dir_struct *dir,
+		    const struct cache_entry *ce, const char *fullname,
+		    const char *tag)
 {
-	struct strbuf name = STRBUF_INIT;
-	int len = max_prefix_len;
-	if (super_prefix)
-		strbuf_addstr(&name, super_prefix);
-	strbuf_addstr(&name, ce->name);
-
-	if (len > ce_namelen(ce))
+	if (max_prefix_len > strlen(fullname))
 		die("git ls-files: internal error - cache entry not superset of prefix");
 
 	if (recurse_submodules && S_ISGITLINK(ce->ce_mode) &&
-	    submodule_path_match(&pathspec, name.buf, ps_matched)) {
-		show_gitlink(ce);
-	} else if (match_pathspec(&pathspec, name.buf, name.len,
-				  len, ps_matched,
+	    is_submodule_active(repo, ce->name)) {
+		show_submodule(repo, dir, ce->name);
+	} else if (match_pathspec(&pathspec, fullname, strlen(fullname),
+				  max_prefix_len, ps_matched,
 				  S_ISDIR(ce->ce_mode) ||
 				  S_ISGITLINK(ce->ce_mode))) {
 		tag = get_tag(ce, tag);
