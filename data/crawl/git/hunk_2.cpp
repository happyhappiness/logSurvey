 
 	todo_list_release(&todo_list);
 	strbuf_addstr(&todo_file, ".backup");
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
 	strbuf_release(&todo_file);
 	res = !!parse_insn_buffer(todo_list.buf.buf, &todo_list);
 
