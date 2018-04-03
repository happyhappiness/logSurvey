	struct strbuf todo_file = STRBUF_INIT;
	struct todo_list todo_list = TODO_LIST_INIT;
	struct strbuf missing = STRBUF_INIT;
	int advise_to_edit_todo = 0, res = 0, i;

	strbuf_addstr(&todo_file, rebase_path_todo());
	if (strbuf_read_file_or_whine(&todo_list.buf, todo_file.buf) < 0) {
		res = -1;
		goto leave_check;
	}
	advise_to_edit_todo = res =
		parse_insn_buffer(todo_list.buf.buf, &todo_list);

