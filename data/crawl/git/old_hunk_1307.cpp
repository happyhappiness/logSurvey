	if (git_config_get_string(key, &value))
		return 1;
	if (parse_notes_merge_strategy(value, strategy))
		git_die_config(key, "unknown notes merge strategy %s", value);

	free(value);
	return 0;