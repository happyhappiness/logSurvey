 	strbuf_release(&format);
 }
 
+static int parse_head(struct commit **head)
+{
+	struct commit *current_head;
+	struct object_id oid;
+
+	if (get_oid("HEAD", &oid)) {
+		current_head = NULL;
+	} else {
+		current_head = lookup_commit_reference(&oid);
+		if (!current_head)
+			return error(_("could not parse HEAD"));
+		if (oidcmp(&oid, &current_head->object.oid)) {
+			warning(_("HEAD %s is not a commit!"),
+				oid_to_hex(&oid));
+		}
+		if (parse_commit(current_head))
+			return error(_("could not parse HEAD commit"));
+	}
+	*head = current_head;
+
+	return 0;
+}
+
+/*
+ * Try to commit without forking 'git commit'. In some cases we need
+ * to run 'git commit' to display an error message
+ *
+ * Returns:
+ *  -1 - error unable to commit
+ *   0 - success
+ *   1 - run 'git commit'
+ */
+static int try_to_commit(struct strbuf *msg, const char *author,
+			 struct replay_opts *opts, unsigned int flags,
+			 struct object_id *oid)
+{
+	struct object_id tree;
+	struct commit *current_head;
+	struct commit_list *parents = NULL;
+	struct commit_extra_header *extra = NULL;
+	struct strbuf err = STRBUF_INIT;
+	struct strbuf amend_msg = STRBUF_INIT;
+	char *amend_author = NULL;
+	const char *gpg_sign;
+	enum commit_msg_cleanup_mode cleanup;
+	int res = 0;
+
+	if (parse_head(&current_head))
+		return -1;
+
+	if (flags & AMEND_MSG) {
+		const char *exclude_gpgsig[] = { "gpgsig", NULL };
+		const char *out_enc = get_commit_output_encoding();
+		const char *message = logmsg_reencode(current_head, NULL,
+						      out_enc);
+
+		if (!msg) {
+			const char *orig_message = NULL;
+
+			find_commit_subject(message, &orig_message);
+			msg = &amend_msg;
+			strbuf_addstr(msg, orig_message);
+		}
+		author = amend_author = get_author(message);
+		unuse_commit_buffer(current_head, message);
+		if (!author) {
+			res = error(_("unable to parse commit author"));
+			goto out;
+		}
+		parents = copy_commit_list(current_head->parents);
+		extra = read_commit_extra_headers(current_head, exclude_gpgsig);
+	} else if (current_head) {
+		commit_list_insert(current_head, &parents);
+	}
+
+	cleanup = (flags & CLEANUP_MSG) ? COMMIT_MSG_CLEANUP_ALL :
+					  default_msg_cleanup;
+	if (cleanup != COMMIT_MSG_CLEANUP_NONE)
+		strbuf_stripspace(msg, cleanup == COMMIT_MSG_CLEANUP_ALL);
+	if (!opts->allow_empty_message && message_is_empty(msg, cleanup)) {
+		res = 1; /* run 'git commit' to display error message */
+		goto out;
+	}
+
+	gpg_sign = opts->gpg_sign ? opts->gpg_sign : default_gpg_sign;
+
+	if (write_cache_as_tree(tree.hash, 0, NULL)) {
+		res = error(_("git write-tree failed to write a tree"));
+		goto out;
+	}
+
+	if (!(flags & ALLOW_EMPTY) && !oidcmp(current_head ?
+					      &current_head->tree->object.oid :
+					      &empty_tree_oid, &tree)) {
+		res = 1; /* run 'git commit' to display error message */
+		goto out;
+	}
+
+	if (commit_tree_extended(msg->buf, msg->len, tree.hash, parents,
+				 oid->hash, author, gpg_sign, extra)) {
+		res = error(_("failed to write commit object"));
+		goto out;
+	}
+
+	if (update_head_with_reflog(current_head, oid,
+				    getenv("GIT_REFLOG_ACTION"), msg, &err)) {
+		res = error("%s", err.buf);
+		goto out;
+	}
+
+	if (flags & AMEND_MSG)
+		commit_post_rewrite(current_head, oid);
+
+out:
+	free_commit_extra_headers(extra);
+	strbuf_release(&err);
+	strbuf_release(&amend_msg);
+	free(amend_author);
+
+	return res;
+}
+
+static int do_commit(const char *msg_file, const char *author,
+		     struct replay_opts *opts, unsigned int flags)
+{
+	int res = 1;
+
+	if (!(flags & EDIT_MSG) && !(flags & VERIFY_MSG)) {
+		struct object_id oid;
+		struct strbuf sb = STRBUF_INIT;
+
+		if (msg_file && strbuf_read_file(&sb, msg_file, 2048) < 0)
+			return error_errno(_("unable to read commit message "
+					     "from '%s'"),
+					   msg_file);
+
+		res = try_to_commit(msg_file ? &sb : NULL, author, opts, flags,
+				    &oid);
+		strbuf_release(&sb);
+		if (!res) {
+			unlink(git_path_cherry_pick_head());
+			unlink(git_path_merge_msg());
+			if (!is_rebase_i(opts))
+				print_commit_summary(NULL, &oid,
+						SUMMARY_SHOW_AUTHOR_DATE);
+			return res;
+		}
+	}
+	if (res == 1)
+		return run_git_commit(msg_file, opts, flags);
+
+	return res;
+}
+
 static int is_original_commit_empty(struct commit *commit)
 {
 	const struct object_id *ptree_oid;
