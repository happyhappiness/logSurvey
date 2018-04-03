		usage_with_options(builtin_config_usage, builtin_config_options);
	}

	if (given_config_source.file &&
			!strcmp(given_config_source.file, "-")) {
		given_config_source.file = NULL;
