	}
	close(fd);

	res = parse_insn_buffer(todo_list->buf.buf, todo_list);
	if (res) {
		if (is_rebase_i(opts))
