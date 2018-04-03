		struct replay_opts *opts)
{
	struct commit_list *cur = NULL;
	struct commit_message msg = { NULL, NULL, NULL, NULL, NULL };
	const char *sha1_abbrev = NULL;
	const char *action_str = opts->action == REVERT ? "revert" : "pick";

	for (cur = todo_list; cur; cur = cur->next) {
		sha1_abbrev = find_unique_abbrev(cur->item->object.sha1, DEFAULT_ABBREV);
		if (get_message(cur->item, &msg))
			return error(_("Cannot get commit message for %s"), sha1_abbrev);
		strbuf_addf(buf, "%s %s %s\n", action_str, sha1_abbrev, msg.subject);
		free_message(&msg);
	}
	return 0;
}