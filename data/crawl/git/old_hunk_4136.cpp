	return 0;
}

/* if new_name == NULL, the section is removed instead */
int git_config_rename_section_in_file(const char *config_filename,
				      const char *old_name, const char *new_name)
{
	int ret = 0, remove = 0;
	char *filename_buf = NULL;
	struct lock_file *lock = xcalloc(sizeof(struct lock_file), 1);
	int out_fd;
	char buf[1024];
	FILE *config_file;

	if (!config_filename)
		config_filename = filename_buf = git_pathdup("config");

	out_fd = hold_lock_file_for_update(lock, config_filename, 0);
	if (out_fd < 0) {
		ret = error("could not lock config file %s", config_filename);
