	free(ref_git_copy);
}

static void copy_or_link_directory(char *src, char *dest)
{
	struct dirent *de;
	struct stat buf;
	int src_len, dest_len;
	DIR *dir;

	dir = opendir(src);
	if (!dir)
		die("failed to open %s\n", src);

	if (mkdir(dest, 0777)) {
		if (errno != EEXIST)
			die("failed to create directory %s\n", dest);
		else if (stat(dest, &buf))
			die("failed to stat %s\n", dest);
		else if (!S_ISDIR(buf.st_mode))
			die("%s exists and is not a directory\n", dest);
	}

	src_len = strlen(src);
	src[src_len] = '/';
	dest_len = strlen(dest);
	dest[dest_len] = '/';

	while ((de = readdir(dir)) != NULL) {
		strcpy(src + src_len + 1, de->d_name);
		strcpy(dest + dest_len + 1, de->d_name);
		if (stat(src, &buf)) {
			warning ("failed to stat %s\n", src);
			continue;
		}
		if (S_ISDIR(buf.st_mode)) {
