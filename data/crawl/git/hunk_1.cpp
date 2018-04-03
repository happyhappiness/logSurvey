 	struct strbuf todo_file = STRBUF_INIT;
 	struct todo_list todo_list = TODO_LIST_INIT;
 	struct strbuf missing = STRBUF_INIT;
-	int advise_to_edit_todo = 0, res = 0, fd, i;
+	int advise_to_edit_todo = 0, res = 0, i;
 
 	strbuf_addstr(&todo_file, rebase_path_todo());
-	fd = open(todo_file.buf, O_RDONLY);
-	if (fd < 0) {
-		res = error_errno(_("could not open '%s'"), todo_file.buf);
-		goto leave_check;
-	}
-	if (strbuf_read(&todo_list.buf, fd, 0) < 0) {
-		close(fd);
-		res = error(_("could not read '%s'."), todo_file.buf);
+	if (strbuf_read_file_or_whine(&todo_list.buf, todo_file.buf) < 0) {
+		res = -1;
 		goto leave_check;
 	}
-	close(fd);
 	advise_to_edit_todo = res =
 		parse_insn_buffer(todo_list.buf.buf, &todo_list);
 
