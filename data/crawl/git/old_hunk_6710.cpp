	int i = 0, ret;
	struct commit_list *j;
	struct strbuf buf;

	if (!strcmp(strategy, "recursive") || !strcmp(strategy, "subtree")) {
		int clean;
