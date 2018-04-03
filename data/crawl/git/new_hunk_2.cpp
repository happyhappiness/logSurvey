
	todo_list_release(&todo_list);
	strbuf_addstr(&todo_file, ".backup");
	if (strbuf_read_file_or_whine(&todo_list.buf, todo_file.buf) < 0) {
		res = -1;
		goto leave_check;
	}
	strbuf_release(&todo_file);
	res = !!parse_insn_buffer(todo_list.buf.buf, &todo_list);

