{
	const char **dir = (const char **)opt->value;
	if (*dir)
		die(_("Two output directories?"));
	*dir = arg;
	return 0;
}
