int git_config_set_multivar(const char *key, const char *value,
	const char *value_regex, int multi_replace)
{
	int i, dot;
	int fd = -1, in_fd;
	int ret;
	char *config_filename;
	struct lock_file *lock = NULL;
	const char *last_dot = strrchr(key, '.');

	if (config_exclusive_filename)
		config_filename = xstrdup(config_exclusive_filename);
	else
		config_filename = git_pathdup("config");

	/*
	 * Since "key" actually contains the section name and the real
	 * key name separated by a dot, we have to know where the dot is.
	 */

	if (last_dot == NULL) {
		error("key does not contain a section: %s", key);
		ret = 2;
		goto out_free;
	}
	store.baselen = last_dot - key;

	store.multi_replace = multi_replace;

	/*
	 * Validate the key and while at it, lower case it for matching.
	 */
	store.key = xmalloc(strlen(key) + 1);
	dot = 0;
	for (i = 0; key[i]; i++) {
		unsigned char c = key[i];
		if (c == '.')
			dot = 1;
		/* Leave the extended basename untouched.. */
		if (!dot || i > store.baselen) {
			if (!iskeychar(c) || (i == store.baselen+1 && !isalpha(c))) {
				error("invalid key: %s", key);
				free(store.key);
				ret = 1;
				goto out_free;
			}
			c = tolower(c);
		} else if (c == '\n') {
			error("invalid key (newline): %s", key);
			free(store.key);
			ret = 1;
			goto out_free;
		}
		store.key[i] = c;
	}
	store.key[i] = 0;

	/*
	 * The lock serves a purpose in addition to locking: the new
