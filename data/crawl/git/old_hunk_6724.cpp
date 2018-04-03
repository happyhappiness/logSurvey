/*
 * Write errors (particularly out of space) can result in
 * failed temporary packs (and more rarely indexes and other
 * files begining with "tmp_") accumulating in the
 * object directory.
 */
static void remove_temporary_files(void)
{
	DIR *dir;
	struct dirent *de;
	char* dirname=get_object_directory();

	dir = opendir(dirname);
	if (!dir) {
		fprintf(stderr, "Unable to open object directory %s\n",
			dirname);
		return;
	}
	while ((de = readdir(dir)) != NULL)
		if (!prefixcmp(de->d_name, "tmp_"))
			prune_tmp_object(dirname, de->d_name);
	closedir(dir);
}

