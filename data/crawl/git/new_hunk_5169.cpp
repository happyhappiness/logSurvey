	struct commit_list *list = NULL, *backup = NULL, *l;
	int retval = -1;
	char *temp_commit_buffer = NULL;
	regex_t regex;

	if (prefix[0] == '!') {
		if (prefix[1] != '!')
			die ("Invalid search pattern: %s", prefix);
		prefix++;
	}

	if (regcomp(&regex, prefix, REG_EXTENDED))
		die("Invalid search pattern: %s", prefix);

	for_each_ref(handle_one_ref, &list);
	for (l = list; l; l = l->next)
		commit_list_insert(l->item, &backup);
