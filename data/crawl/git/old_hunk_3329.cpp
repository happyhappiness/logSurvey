	free(buf);
}

static void remove_subtree(const char *path)
{
	DIR *dir = opendir(path);
	struct dirent *de;
	char pathbuf[PATH_MAX];
	char *name;

	if (!dir)
		die_errno("cannot opendir '%s'", path);
	strcpy(pathbuf, path);
	name = pathbuf + strlen(path);
	*name++ = '/';
	while ((de = readdir(dir)) != NULL) {
		struct stat st;
		if (is_dot_or_dotdot(de->d_name))
			continue;
		strcpy(name, de->d_name);
		if (lstat(pathbuf, &st))
			die_errno("cannot lstat '%s'", pathbuf);
		if (S_ISDIR(st.st_mode))
			remove_subtree(pathbuf);
		else if (unlink(pathbuf))
			die_errno("cannot unlink '%s'", pathbuf);
	}
	closedir(dir);
	if (rmdir(path))
		die_errno("cannot rmdir '%s'", path);
}

static int create_file(const char *path, unsigned int mode)
