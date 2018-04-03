 	}
 	strbuf_release(&buf);
 
-	fd = open(todo_file, O_RDONLY);
-	if (fd < 0) {
-		return error_errno(_("could not open '%s'"), todo_file);
-	}
-	if (strbuf_read(&todo_list.buf, fd, 0) < 0) {
-		close(fd);
-		return error(_("could not read '%s'."), todo_file);
-	}
-	close(fd);
+	if (strbuf_read_file_or_whine(&todo_list.buf, todo_file) < 0)
+		return -1;
 	if (parse_insn_buffer(todo_list.buf.buf, &todo_list) < 0) {
 		todo_list_release(&todo_list);
 		return -1;
