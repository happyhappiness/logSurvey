	const char *todo_file = rebase_path_todo();
	struct todo_list todo_list = TODO_LIST_INIT;
	struct hashmap subject2item;
	int res = 0, rearranged = 0, *next, *tail, i;
	char **subjects;

	if (strbuf_read_file_or_whine(&todo_list.buf, todo_file) < 0)
		return -1;
	if (parse_insn_buffer(todo_list.buf.buf, &todo_list) < 0) {
		todo_list_release(&todo_list);
		return -1;