	char name[PATH_MAX];
	int ret = -1;
	int i;
	struct string_list list = {NULL, 0, 0, 1};

	if (populate_maildir_list(&list, maildir) < 0)
		goto out;

	for (i = 0; i < list.nr; i++) {
		FILE *f;
		snprintf(file, sizeof(file), "%s/%s", maildir, list.items[i].string);
		f = fopen(file, "r");
		if (!f) {
			error("cannot open mail %s (%s)", file, strerror(errno));
