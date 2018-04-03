	return count;
}

static int read_populate_todo(struct todo_list *todo_list,
			struct replay_opts *opts)
{
	struct stat st;
	const char *todo_file = get_todo_path(opts);
	int fd, res;

	strbuf_reset(&todo_list->buf);
	fd = open(todo_file, O_RDONLY);
	if (fd < 0)
		return error_errno(_("could not open '%s'"), todo_file);
	if (strbuf_read(&todo_list->buf, fd, 0) < 0) {
		close(fd);
		return error(_("could not read '%s'."), todo_file);
	}
	close(fd);

	res = stat(todo_file, &st);
	if (res)
