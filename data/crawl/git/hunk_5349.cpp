 	return 0;
 }
 
-int notes_copy_from_stdin(int force)
+
+combine_notes_fn *parse_combine_notes_fn(const char *v)
+{
+	if (!strcasecmp(v, "overwrite"))
+		return combine_notes_overwrite;
+	else if (!strcasecmp(v, "ignore"))
+		return combine_notes_ignore;
+	else if (!strcasecmp(v, "concatenate"))
+		return combine_notes_concatenate;
+	else
+		return NULL;
+}
+
+static int notes_rewrite_config(const char *k, const char *v, void *cb)
+{
+	struct notes_rewrite_cfg *c = cb;
+	if (!prefixcmp(k, "notes.rewrite.") && !strcmp(k+14, c->cmd)) {
+		c->enabled = git_config_bool(k, v);
+		return 0;
+	} else if (!c->mode_from_env && !strcmp(k, "notes.rewritemode")) {
+		if (!v)
+			config_error_nonbool(k);
+		c->combine = parse_combine_notes_fn(v);
+		if (!c->combine) {
+			error("Bad notes.rewriteMode value: '%s'", v);
+			return 1;
+		}
+		return 0;
+	} else if (!c->refs_from_env && !strcmp(k, "notes.rewriteref")) {
+		/* note that a refs/ prefix is implied in the
+		 * underlying for_each_glob_ref */
+		if (!prefixcmp(v, "refs/notes/"))
+			string_list_add_refs_by_glob(c->refs, v);
+		else
+			warning("Refusing to rewrite notes in %s"
+				" (outside of refs/notes/)", v);
+		return 0;
+	}
+
+	return 0;
+}
+
+
+struct notes_rewrite_cfg *init_copy_notes_for_rewrite(const char *cmd)
+{
+	struct notes_rewrite_cfg *c = xmalloc(sizeof(struct notes_rewrite_cfg));
+	const char *rewrite_mode_env = getenv(GIT_NOTES_REWRITE_MODE_ENVIRONMENT);
+	const char *rewrite_refs_env = getenv(GIT_NOTES_REWRITE_REF_ENVIRONMENT);
+	c->cmd = cmd;
+	c->enabled = 1;
+	c->combine = combine_notes_concatenate;
+	c->refs = xcalloc(1, sizeof(struct string_list));
+	c->refs->strdup_strings = 1;
+	c->refs_from_env = 0;
+	c->mode_from_env = 0;
+	if (rewrite_mode_env) {
+		c->mode_from_env = 1;
+		c->combine = parse_combine_notes_fn(rewrite_mode_env);
+		if (!c->combine)
+			error("Bad " GIT_NOTES_REWRITE_MODE_ENVIRONMENT
+			      " value: '%s'", rewrite_mode_env);
+	}
+	if (rewrite_refs_env) {
+		c->refs_from_env = 1;
+		string_list_add_refs_from_colon_sep(c->refs, rewrite_refs_env);
+	}
+	git_config(notes_rewrite_config, c);
+	if (!c->enabled || !c->refs->nr) {
+		string_list_clear(c->refs, 0);
+		free(c->refs);
+		free(c);
+		return NULL;
+	}
+	c->trees = load_notes_trees(c->refs);
+	string_list_clear(c->refs, 0);
+	free(c->refs);
+	return c;
+}
+
+int copy_note_for_rewrite(struct notes_rewrite_cfg *c,
+			  const unsigned char *from_obj, const unsigned char *to_obj)
+{
+	int ret = 0;
+	int i;
+	for (i = 0; c->trees[i]; i++)
+		ret = copy_note(c->trees[i], from_obj, to_obj, 1, c->combine) || ret;
+	return ret;
+}
+
+void finish_copy_notes_for_rewrite(struct notes_rewrite_cfg *c)
+{
+	int i;
+	for (i = 0; c->trees[i]; i++) {
+		commit_notes(c->trees[i], "Notes added by 'git notes copy'");
+		free_notes(c->trees[i]);
+	}
+	free(c->trees);
+	free(c);
+}
+
+int notes_copy_from_stdin(int force, const char *rewrite_cmd)
 {
 	struct strbuf buf = STRBUF_INIT;
+	struct notes_rewrite_cfg *c = NULL;
 	struct notes_tree *t;
 	int ret = 0;
 
-	init_notes(NULL, NULL, NULL, 0);
-	t = &default_notes_tree;
+	if (rewrite_cmd) {
+		c = init_copy_notes_for_rewrite(rewrite_cmd);
+		if (!c)
+			return 0;
+	} else {
+		init_notes(NULL, NULL, NULL, 0);
+		t = &default_notes_tree;
+	}
 
 	while (strbuf_getline(&buf, stdin, '\n') != EOF) {
 		unsigned char from_obj[20], to_obj[20];
