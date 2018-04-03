static int read_populate_todo(struct commit_list **todo_list,
			struct replay_opts *opts)
{
	struct strbuf buf = STRBUF_INIT;
	int fd, res;

	fd = open(git_path_todo_file(), O_RDONLY);
	if (fd < 0)
		return error_errno(_("Could not open %s"),
				   git_path_todo_file());
	if (strbuf_read(&buf, fd, 0) < 0) {
		close(fd);
		strbuf_release(&buf);
		return error(_("Could not read %s."), git_path_todo_file());
	}
	close(fd);

	res = parse_insn_buffer(buf.buf, todo_list, opts);
	strbuf_release(&buf);
	if (res)
		return error(_("Unusable instruction sheet: %s"),
			git_path_todo_file());
	return 0;
}

