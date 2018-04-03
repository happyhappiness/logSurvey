int git_config_set_multivar(const char *key, const char *value,
	const char *value_regex, int multi_replace)
{
	int fd = -1, in_fd;
	int ret;
	char *config_filename;
	struct lock_file *lock = NULL;

	if (config_exclusive_filename)
		config_filename = xstrdup(config_exclusive_filename);
	else
		config_filename = git_pathdup("config");

	/* parse-key returns negative; flip the sign to feed exit(3) */
	ret = 0 - git_config_parse_key(key, &store.key, &store.baselen);
	if (ret)
		goto out_free;

	store.multi_replace = multi_replace;


	/*
	 * The lock serves a purpose in addition to locking: the new
