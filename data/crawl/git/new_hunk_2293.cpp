
	if (prefix[0] == '!') {
		if (prefix[1] != '!')
			return -1;
		prefix++;
	}

	if (regcomp(&regex, prefix, REG_EXTENDED))
		return -1;

	for (l = list; l; l = l->next) {
		l->item->object.flags |= ONELINE_SEEN;
