	if (get_colorbool_slot)
	    actions |= ACTION_GET_COLORBOOL;

	if ((get_color_slot || get_colorbool_slot) && types) {
		error("--get-color and variable type are incoherent");
		usage_with_options(builtin_config_usage, builtin_config_options);
	}

	if (HAS_MULTI_BITS(actions)) {
		error("only one action at a time.");
		usage_with_options(builtin_config_usage, builtin_config_options);