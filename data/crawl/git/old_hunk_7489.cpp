
	if (!strcmp("recursive", ep)) {
		if (!value)
			return error("%s: lacks value", var);
		fn->recursive = strdup(value);
		return 0;
	}