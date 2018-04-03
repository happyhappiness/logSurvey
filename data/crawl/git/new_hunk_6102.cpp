	const char *subkey = strrchr(name, '.');

	if (!subkey)
		return 0;

	if (!strcmp(subkey, ".path")) {
		if (!value)
