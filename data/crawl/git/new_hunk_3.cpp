	}
	strbuf_release(&buf);

	if (strbuf_read_file_or_whine(&todo_list.buf, todo_file) < 0)
		return -1;
	if (parse_insn_buffer(todo_list.buf.buf, &todo_list) < 0) {
		todo_list_release(&todo_list);
		return -1;
