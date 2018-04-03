{
	struct commit_list *list = NULL, *backup = NULL, *l;
	int retval = -1;

	if (prefix[0] == '!') {
		if (prefix[1] != '!')
			die ("Invalid search pattern: %s", prefix);
		prefix++;
	}
	if (!save_commit_buffer)
		return error("Could not expand oneline-name.");
	for_each_ref(handle_one_ref, &list);
	for (l = list; l; l = l->next)
		commit_list_insert(l->item, &backup);
	while (list) {
		char *p;
		struct commit *commit;

		commit = pop_most_recent_commit(&list, ONELINE_SEEN);
		parse_object(commit->object.sha1);
		if (!commit->buffer || !(p = strstr(commit->buffer, "\n\n")))
			continue;
		if (!prefixcmp(p + 2, prefix)) {
			hashcpy(sha1, commit->object.sha1);
			retval = 0;
			break;
		}
	}
	free_commit_list(list);
	for (l = backup; l; l = l->next)
		clear_commit_marks(l->item, ONELINE_SEEN);