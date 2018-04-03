	if (get_colorbool_slot)
	    actions |= ACTION_GET_COLORBOOL;

	if (HAS_MULTI_BITS(actions)) {
		error("only one action at a time.");
		usage_with_options(builtin_config_usage, builtin_config_options);