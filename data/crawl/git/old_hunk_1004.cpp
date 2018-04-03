	return 0;
}

static int format_todo(struct strbuf *buf, struct commit_list *todo_list,
		struct replay_opts *opts)
{
	struct commit_list *cur = NULL;
	const char *sha1_abbrev = NULL;
	const char *action_str = opts->action == REPLAY_REVERT ? "revert" : "pick";
	const char *subject;
	int subject_len;

	for (cur = todo_list; cur; cur = cur->next) {
		const char *commit_buffer = get_commit_buffer(cur->item, NULL);
		sha1_abbrev = find_unique_abbrev(cur->item->object.oid.hash, DEFAULT_ABBREV);
		subject_len = find_commit_subject(commit_buffer, &subject);
		strbuf_addf(buf, "%s %s %.*s\n", action_str, sha1_abbrev,
			subject_len, subject);
		unuse_commit_buffer(cur->item, commit_buffer);
	}
	return 0;
}

static struct commit *parse_insn_line(char *bol, char *eol, struct replay_opts *opts)
{
	unsigned char commit_sha1[20];
	enum replay_action action;
	char *end_of_object_name;
	int saved, status, padding;

	if (starts_with(bol, "pick")) {
		action = REPLAY_PICK;
		bol += strlen("pick");
	} else if (starts_with(bol, "revert")) {
		action = REPLAY_REVERT;
		bol += strlen("revert");
	} else
		return NULL;

	/* Eat up extra spaces/ tabs before object name */
	padding = strspn(bol, " \t");
	if (!padding)
		return NULL;
	bol += padding;

	end_of_object_name = bol + strcspn(bol, " \t\n");
	saved = *end_of_object_name;
	*end_of_object_name = '\0';
	status = get_sha1(bol, commit_sha1);
	*end_of_object_name = saved;

	/*
	 * Verify that the action matches up with the one in
	 * opts; we don't support arbitrary instructions
	 */
	if (action != opts->action) {
		if (action == REPLAY_REVERT)
		      error((opts->action == REPLAY_REVERT)
			    ? _("Cannot revert during another revert.")
			    : _("Cannot revert during a cherry-pick."));
		else
		      error((opts->action == REPLAY_REVERT)
			    ? _("Cannot cherry-pick during a revert.")
			    : _("Cannot cherry-pick during another cherry-pick."));
		return NULL;
	}

	if (status < 0)
		return NULL;

	return lookup_commit_reference(commit_sha1);
}

static int parse_insn_buffer(char *buf, struct commit_list **todo_list,
			struct replay_opts *opts)
{
	struct commit_list **next = todo_list;
	struct commit *commit;
	char *p = buf;
	int i;

	for (i = 1; *p; i++) {
		char *eol = strchrnul(p, '\n');
		commit = parse_insn_line(p, eol, opts);
		if (!commit)
			return error(_("Could not parse line %d."), i);
		next = commit_list_append(commit, next);
		p = *eol ? eol + 1 : eol;
	}
	if (!*todo_list)
		return error(_("No commits parsed."));
	return 0;
}

static int read_populate_todo(struct commit_list **todo_list,
			struct replay_opts *opts)
{
	const char *todo_file = get_todo_path(opts);
	struct strbuf buf = STRBUF_INIT;
	int fd, res;

	fd = open(todo_file, O_RDONLY);
	if (fd < 0)
		return error_errno(_("Could not open %s"), todo_file);
	if (strbuf_read(&buf, fd, 0) < 0) {
		close(fd);
		strbuf_release(&buf);
		return error(_("Could not read %s."), todo_file);
	}
	close(fd);

	res = parse_insn_buffer(buf.buf, todo_list, opts);
	strbuf_release(&buf);
	if (res)
		return error(_("Unusable instruction sheet: %s"), todo_file);
	return 0;
