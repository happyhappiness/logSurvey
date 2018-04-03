{
	if (!strcmp(var, "user.signingkey")) {
		if (!value)
			die("user.signingkey without value");
		set_signingkey(value);
		return 0;
	}