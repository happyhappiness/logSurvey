	return git_default_config(var, value, cb);
}

static void append_option(const char **cmd, const char *opt, int max_length)
{
	int i;

	for (i = 0; cmd[i]; i++)
		;

	if (i + 2 >= max_length)
		die(_("Too many options specified"));
	cmd[i++] = opt;
	cmd[i] = NULL;
}

static int too_many_loose_objects(void)
{
	/*
