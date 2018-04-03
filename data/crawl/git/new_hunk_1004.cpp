	return 0;
}

struct todo_item {
	enum todo_command command;
	struct commit *commit;
	size_t offset_in_buf;
};

struct todo_list {
	struct strbuf buf;
	struct todo_item *items;
	int nr, alloc, current;
};

#define TODO_LIST_INIT { STRBUF_INIT }

static void todo_list_release(struct todo_list *todo_list)
{
	strbuf_release(&todo_list->buf);
	free(todo_list->items);
	todo_list->items = NULL;
	todo_list->nr = todo_list->alloc = 0;
}

static struct todo_item *append_new_todo(struct todo_list *todo_list)
{
	ALLOC_GROW(todo_list->items, todo_list->nr + 1, todo_list->alloc);
	return todo_list->items + todo_list->nr++;
}

static int parse_insn_line(struct todo_item *item, const char *bol, char *eol)
{
	unsigned char commit_sha1[20];
	char *end_of_object_name;
	int i, saved, status, padding;

	for (i = 0; i < ARRAY_SIZE(todo_command_strings); i++)
		if (skip_prefix(bol, todo_command_strings[i], &bol)) {
			item->command = i;
			break;
		}
	if (i >= ARRAY_SIZE(todo_command_strings))
		return -1;

	/* Eat up extra spaces/ tabs before object name */
	padding = strspn(bol, " \t");
	if (!padding)
		return -1;
	bol += padding;

	end_of_object_name = (char *) bol + strcspn(bol, " \t\n");
	saved = *end_of_object_name;
	*end_of_object_name = '\0';
	status = get_sha1(bol, commit_sha1);
	*end_of_object_name = saved;

	if (status < 0)
		return -1;

	item->commit = lookup_commit_reference(commit_sha1);
	return !item->commit;
}

static int parse_insn_buffer(char *buf, struct todo_list *todo_list)
{
	struct todo_item *item;
	char *p = buf, *next_p;
	int i, res = 0;

	for (i = 1; *p; i++, p = next_p) {
		char *eol = strchrnul(p, '\n');

		next_p = *eol ? eol + 1 /* skip LF */ : eol;

		item = append_new_todo(todo_list);
		item->offset_in_buf = p - todo_list->buf.buf;
		if (parse_insn_line(item, p, eol)) {
			res = error(_("Invalid line %d: %.*s"),
				i, (int)(eol - p), p);
			item->command = -1;
		}
	}
	if (!todo_list->nr)
		return error(_("No commits parsed."));
	return res;
}

static int read_populate_todo(struct todo_list *todo_list,
			struct replay_opts *opts)
{
	const char *todo_file = get_todo_path(opts);
	int fd, res;

	strbuf_reset(&todo_list->buf);
	fd = open(todo_file, O_RDONLY);
	if (fd < 0)
		return error_errno(_("Could not open %s"), todo_file);
	if (strbuf_read(&todo_list->buf, fd, 0) < 0) {
		close(fd);
		return error(_("Could not read %s."), todo_file);
	}
	close(fd);

	res = parse_insn_buffer(todo_list->buf.buf, todo_list);
	if (!res) {
		enum todo_command valid =
			opts->action == REPLAY_PICK ? TODO_PICK : TODO_REVERT;
		int i;

		for (i = 0; i < todo_list->nr; i++)
			if (valid == todo_list->items[i].command)
				continue;
			else if (valid == TODO_PICK)
				return error(_("Cannot cherry-pick during a revert."));
			else
				return error(_("Cannot revert during a cherry-pick."));
	}

	if (res)
		return error(_("Unusable instruction sheet: %s"), todo_file);
	return 0;
