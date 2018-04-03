	return 0;
}

int git_config_parse_environment(void) {
	const char *env = getenv(CONFIG_DATA_ENVIRONMENT);
	char *envw;
	const char **argv = NULL;
	int nr = 0, alloc = 0;
	int i;

	if (!env)
		return 0;
	/* sq_dequote will write over it */
	envw = xstrdup(env);

	if (sq_dequote_to_argv(envw, &argv, &nr, &alloc) < 0) {
		free(envw);
		return error("bogus format in " CONFIG_DATA_ENVIRONMENT);
	}

	for (i = 0; i < nr; i++) {
		if (git_config_parse_parameter(argv[i]) < 0) {
			error("bogus config parameter: %s", argv[i]);
			free(argv);
			free(envw);
			return -1;
		}
	}

	free(argv);
	free(envw);
	return 0;
}

static int get_next_char(void)
{
	int c;
