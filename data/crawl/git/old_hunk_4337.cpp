	return git_config_set_multivar(key, tmp->buf, "^$", 0);
}

static int add(int argc, const char **argv)
{
	int fetch = 0, mirror = 0, fetch_tags = TAGS_DEFAULT;
	struct string_list track = STRING_LIST_INIT_NODUP;
	const char *master = NULL;
	struct remote *remote;
