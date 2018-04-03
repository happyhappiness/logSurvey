 	struct commit_list *j;
 	struct strbuf buf;
 
-	args = xmalloc((4 + commit_list_count(common) +
-			commit_list_count(remoteheads)) * sizeof(char *));
-	strbuf_init(&buf, 0);
-	strbuf_addf(&buf, "merge-%s", strategy);
-	args[i++] = buf.buf;
-	for (j = common; j; j = j->next)
-		args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
-	args[i++] = "--";
-	args[i++] = head_arg;
-	for (j = remoteheads; j; j = j->next)
-		args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
-	args[i] = NULL;
-	ret = run_command_v_opt(args, RUN_GIT_CMD);
-	strbuf_release(&buf);
-	i = 1;
-	for (j = common; j; j = j->next)
-		free((void *)args[i++]);
-	i += 2;
-	for (j = remoteheads; j; j = j->next)
-		free((void *)args[i++]);
-	free(args);
-	return -ret;
+	if (!strcmp(strategy, "recursive") || !strcmp(strategy, "subtree")) {
+		int clean;
+		struct commit *result;
+		struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
+		int index_fd;
+		struct commit_list *reversed = NULL;
+		struct merge_options o;
+
+		if (remoteheads->next) {
+			error("Not handling anything other than two heads merge.");
+			return 2;
+		}
+
+		init_merge_options(&o);
+		if (!strcmp(strategy, "subtree"))
+			o.subtree_merge = 1;
+
+		o.branch1 = head_arg;
+		o.branch2 = remoteheads->item->util;
+
+		for (j = common; j; j = j->next)
+			commit_list_insert(j->item, &reversed);
+
+		index_fd = hold_locked_index(lock, 1);
+		clean = merge_recursive(&o, lookup_commit(head),
+				remoteheads->item, reversed, &result);
+		if (active_cache_changed &&
+				(write_cache(index_fd, active_cache, active_nr) ||
+				 commit_locked_index(lock)))
+			die ("unable to write %s", get_index_file());
+		return clean ? 0 : 1;
+	} else {
+		args = xmalloc((4 + commit_list_count(common) +
+					commit_list_count(remoteheads)) * sizeof(char *));
+		strbuf_init(&buf, 0);
+		strbuf_addf(&buf, "merge-%s", strategy);
+		args[i++] = buf.buf;
+		for (j = common; j; j = j->next)
+			args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
+		args[i++] = "--";
+		args[i++] = head_arg;
+		for (j = remoteheads; j; j = j->next)
+			args[i++] = xstrdup(sha1_to_hex(j->item->object.sha1));
+		args[i] = NULL;
+		ret = run_command_v_opt(args, RUN_GIT_CMD);
+		strbuf_release(&buf);
+		i = 1;
+		for (j = common; j; j = j->next)
+			free((void *)args[i++]);
+		i += 2;
+		for (j = remoteheads; j; j = j->next)
+			free((void *)args[i++]);
+		free(args);
+		discard_cache();
+		if (read_cache() < 0)
+			die("failed to read the cache");
+		return -ret;
+	}
 }
 
 static void count_diff_files(struct diff_queue_struct *q,
