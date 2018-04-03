{
	if (!strcmp(var, "user.signingkey")) {
		if (!value)
			return config_error_nonbool(value);
		set_signingkey(value);
		return 0;
	}