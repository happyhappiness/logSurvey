
	if (!strcmp("smudge", ep)) {
		if (!value)
			return config_error_nonbool(var);
		drv->smudge = strdup(value);
		return 0;
	}

	if (!strcmp("clean", ep)) {
		if (!value)
			return config_error_nonbool(var);
		drv->clean = strdup(value);
		return 0;
	}