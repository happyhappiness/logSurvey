 		die("git write-tree failed to write a tree");
 }
 
-static int try_merge_strategy(const char *strategy, struct commit_list *common,
-			      const char *head_arg)
+static int try_merge_command(const char *strategy, struct commit_list *common,
+			     const char *head_arg, struct commit_list *remotes)
 {
 	const char **args;
 	int i = 0, x = 0, ret;
 	struct commit_list *j;
 	struct strbuf buf = STRBUF_INIT;
+
+	args = xmalloc((4 + xopts_nr + commit_list_count(common) +
+			commit_list_count(remotes)) * sizeof(char *));
+	strbuf_addf(&buf, "merge-%s", strategy);
+	args[i++] = buf.buf;
+	for (x = 0; x < xopts_nr; x++) {
+		char *s = xmalloc(strlen(xopts[x])+2+1);
+		strcpy(s, "--");
+		strcpy(s+2, xopts[x]);
+		args[i++] = s;
+	}
+	for (j = common; j; j = j->next)
+		args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
+	args[i++] = "--";
+	args[i++] = head_arg;
+	for (j = remotes; j; j = j->next)
+		args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
+	args[i] = NULL;
+	ret = run_command_v_opt(args, RUN_GIT_CMD);
+	strbuf_release(&buf);
+	i = 1;
+	for (x = 0; x < xopts_nr; x++)
+		free((void *)args[i++]);
+	for (j = common; j; j = j->next)
+		free((void *)args[i++]);
+	i += 2;
+	for (j = remotes; j; j = j->next)
+		free((void *)args[i++]);
+	free(args);
+	discard_cache();
+	if (read_cache() < 0)
+		die("failed to read the cache");
+	resolve_undo_clear();
+
+	return ret;
+}
+
+static int try_merge_strategy(const char *strategy, struct commit_list *common,
+			      const char *head_arg)
+{
 	int index_fd;
 	struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
 
