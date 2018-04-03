static void list_commands(const char *exec_path)
{
	unsigned int longest = 0;
	const char *prefix = "git-";
	int prefix_len = strlen(prefix);
	DIR *dir = opendir(exec_path);
	struct dirent *de;

	if (!dir || chdir(exec_path)) {
		fprintf(stderr, "git: '%s': %s\n", exec_path, strerror(errno));
		exit(1);
	}

	while ((de = readdir(dir)) != NULL) {
		struct stat st;
		int entlen;

		if (prefixcmp(de->d_name, prefix))
			continue;

		if (stat(de->d_name, &st) || /* stat, not lstat */
		    !S_ISREG(st.st_mode) ||
		    !(st.st_mode & S_IXUSR))
			continue;