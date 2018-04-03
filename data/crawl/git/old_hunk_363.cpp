	return do_git_config_sequence(opts, fn, data);
}

static void git_config_raw(config_fn_t fn, void *data)
{
	struct config_options opts = {0};

	opts.respect_includes = 1;
	if (have_git_dir()) {
		opts.commondir = get_git_common_dir();
		opts.git_dir = get_git_dir();
	}

	if (config_with_options(fn, data, NULL, &opts) < 0)
		/*
		 * config_with_options() normally returns only
		 * zero, as most errors are fatal, and
		 * non-fatal potential errors are guarded by "if"
		 * statements that are entered only when no error is
		 * possible.
		 *
		 * If we ever encounter a non-fatal error, it means
		 * something went really wrong and we should stop
		 * immediately.
		 */
		die(_("unknown error occurred while reading the configuration files"));
}

static void configset_iter(struct config_set *cs, config_fn_t fn, void *data)
{
	int i, value_index;
