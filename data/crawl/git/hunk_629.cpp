 	}
 	close(fd);
 
+	res = stat(todo_file, &st);
+	if (res)
+		return error(_("could not stat '%s'"), todo_file);
+	fill_stat_data(&todo_list->stat, &st);
+
 	res = parse_insn_buffer(todo_list->buf.buf, todo_list);
 	if (res) {
 		if (is_rebase_i(opts))
