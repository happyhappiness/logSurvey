		struct replay_opts *opts)
{
	struct commit_list *cur = NULL;
	const char *sha1_abbrev = NULL;
	const char *action_str = opts->action == REVERT ? "revert" : "pick";
	const char *subject;
	int subject_len;

	for (cur = todo_list; cur; cur = cur->next) {
		sha1_abbrev = find_unique_abbrev(cur->item->object.sha1, DEFAULT_ABBREV);
		subject_len = find_commit_subject(cur->item->buffer, &subject);
		strbuf_addf(buf, "%s %s %.*s\n", action_str, sha1_abbrev,
			subject_len, subject);
	}
	return 0;
}