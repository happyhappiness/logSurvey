{
	DIR *dir;
	struct dirent *dent;

	if ((dir = opendir(path)) == NULL) {
		error("cannot opendir %s (%s)", path, strerror(errno));
		return -1;
	}

	while ((dent = readdir(dir)) != NULL) {
		if (dent->d_name[0] == '.')
			continue;
		path_list_insert(dent->d_name, list);
	}

	closedir(dir);

	return 0;
}

static int split_maildir(const char *maildir, const char *dir,
	int nr_prec, int skip)
{
	char file[PATH_MAX];
	char curdir[PATH_MAX];
	char name[PATH_MAX];
	int ret = -1;
	int i;
	struct path_list list = {NULL, 0, 0, 1};

	snprintf(curdir, sizeof(curdir), "%s/cur", maildir);
	if (populate_maildir_list(&list, curdir) < 0)
		goto out;

	for (i = 0; i < list.nr; i++) {
		FILE *f;
		snprintf(file, sizeof(file), "%s/%s", curdir, list.items[i].path);
		f = fopen(file, "r");
		if (!f) {
			error("cannot open mail %s (%s)", file, strerror(errno));
