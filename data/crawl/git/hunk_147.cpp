 static GIT_PATH_FUNC(rebase_path_strategy_opts, "rebase-merge/strategy_opts")
 static GIT_PATH_FUNC(rebase_path_allow_rerere_autoupdate, "rebase-merge/allow_rerere_autoupdate")
 
+static int git_sequencer_config(const char *k, const char *v, void *cb)
+{
+	struct replay_opts *opts = cb;
+	int status;
+
+	if (!strcmp(k, "commit.cleanup")) {
+		const char *s;
+
+		status = git_config_string(&s, k, v);
+		if (status)
+			return status;
+
+		if (!strcmp(s, "verbatim"))
+			opts->default_msg_cleanup = COMMIT_MSG_CLEANUP_NONE;
+		else if (!strcmp(s, "whitespace"))
+			opts->default_msg_cleanup = COMMIT_MSG_CLEANUP_SPACE;
+		else if (!strcmp(s, "strip"))
+			opts->default_msg_cleanup = COMMIT_MSG_CLEANUP_ALL;
+		else if (!strcmp(s, "scissors"))
+			opts->default_msg_cleanup = COMMIT_MSG_CLEANUP_SPACE;
+		else
+			warning(_("invalid commit message cleanup mode '%s'"),
+				  s);
+
+		return status;
+	}
+
+	if (!strcmp(k, "commit.gpgsign")) {
+		opts->gpg_sign = git_config_bool(k, v) ? "" : NULL;
+		return 0;
+	}
+
+	status = git_gpg_config(k, v, NULL);
+	if (status)
+		return status;
+
+	return git_diff_basic_config(k, v, NULL);
+}
+
+void sequencer_init_config(struct replay_opts *opts)
+{
+	opts->default_msg_cleanup = COMMIT_MSG_CLEANUP_NONE;
+	git_config(git_sequencer_config, opts);
+}
+
 static inline int is_rebase_i(const struct replay_opts *opts)
 {
 	return opts->action == REPLAY_INTERACTIVE_REBASE;
