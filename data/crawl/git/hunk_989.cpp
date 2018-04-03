 
 	fd = hold_lock_file_for_update(&todo_lock, todo_path, 0);
 	if (fd < 0)
-		return error_errno(_("Could not lock '%s'"), todo_path);
+		return error_errno(_("could not lock '%s'"), todo_path);
 	offset = next < todo_list->nr ?
 		todo_list->items[next].offset_in_buf : todo_list->buf.len;
 	if (write_in_full(fd, todo_list->buf.buf + offset,
 			todo_list->buf.len - offset) < 0)
-		return error_errno(_("Could not write to '%s'"), todo_path);
+		return error_errno(_("could not write to '%s'"), todo_path);
 	if (commit_lock_file(&todo_lock) < 0)
-		return error(_("Error wrapping up '%s'."), todo_path);
+		return error(_("failed to finalize '%s'."), todo_path);
 	return 0;
 }
 
