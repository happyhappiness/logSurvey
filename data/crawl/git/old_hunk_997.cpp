	close(fd);

	res = parse_insn_buffer(todo_list->buf.buf, todo_list);
	if (!res) {
		enum todo_command valid =
			opts->action == REPLAY_PICK ? TODO_PICK : TODO_REVERT;
		int i;
