{
	struct commit_list *backup = NULL, *l;
	int found = 0;
	regex_t regex;

	if (prefix[0] == '!') {
		if (prefix[1] != '!')
			die ("Invalid search pattern: %s", prefix);
		prefix++;
	}

	if (regcomp(&regex, prefix, REG_EXTENDED))
