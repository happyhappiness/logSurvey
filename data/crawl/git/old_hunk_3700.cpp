{
	if (!value)
		return config_error_nonbool(var);
	if (!strcmp(value, "never") || !strcmp(value, "false")) {
		*expire = 0;
		return 0;
	}
	*expire = approxidate(value);
	return 0;
}

