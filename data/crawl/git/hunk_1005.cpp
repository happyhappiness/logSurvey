 	return -1;
 }
 
-static int save_todo(struct commit_list *todo_list, struct replay_opts *opts)
+static int save_todo(struct todo_list *todo_list, struct replay_opts *opts)
 {
 	static struct lock_file todo_lock;
-	struct strbuf buf = STRBUF_INIT;
-	int fd;
+	const char *todo_path = get_todo_path(opts);
+	int next = todo_list->current, offset, fd;
 
-	fd = hold_lock_file_for_update(&todo_lock, git_path_todo_file(), 0);
+	fd = hold_lock_file_for_update(&todo_lock, todo_path, 0);
 	if (fd < 0)
-		return error_errno(_("Could not lock '%s'"),
-				   git_path_todo_file());
-	if (format_todo(&buf, todo_list, opts) < 0) {
-		strbuf_release(&buf);
-		return error(_("Could not format %s."), git_path_todo_file());
-	}
-	if (write_in_full(fd, buf.buf, buf.len) < 0) {
-		strbuf_release(&buf);
-		return error_errno(_("Could not write to %s"),
-				   git_path_todo_file());
-	}
-	if (commit_lock_file(&todo_lock) < 0) {
-		strbuf_release(&buf);
-		return error(_("Error wrapping up %s."), git_path_todo_file());
-	}
-	strbuf_release(&buf);
+		return error_errno(_("Could not lock '%s'"), todo_path);
+	offset = next < todo_list->nr ?
+		todo_list->items[next].offset_in_buf : todo_list->buf.len;
+	if (write_in_full(fd, todo_list->buf.buf + offset,
+			todo_list->buf.len - offset) < 0)
+		return error_errno(_("Could not write to '%s'"), todo_path);
+	if (commit_lock_file(&todo_lock) < 0)
+		return error(_("Error wrapping up %s."), todo_path);
 	return 0;
 }
 
