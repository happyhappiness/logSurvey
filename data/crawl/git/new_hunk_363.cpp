	return do_git_config_sequence(opts, fn, data);
}

static void configset_iter(struct config_set *cs, config_fn_t fn, void *data)
{
	int i, value_index;
