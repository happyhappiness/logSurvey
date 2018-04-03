{
	struct commit_list *backup = NULL, *l;
	int found = 0;
	int negative = 0;
	regex_t regex;

	if (prefix[0] == '!') {
		prefix++;

		if (prefix[0] == '-') {
			prefix++;
			negative = 1;
		} else if (prefix[0] != '!') {
			die ("Invalid search pattern: %s", prefix);
		}
	}

	if (regcomp(&regex, prefix, REG_EXTENDED))
