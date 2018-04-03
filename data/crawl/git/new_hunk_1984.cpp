	envw = xstrdup(env);

	if (sq_dequote_to_argv(envw, &argv, &nr, &alloc) < 0) {
		ret = error("bogus format in " CONFIG_DATA_ENVIRONMENT);
		goto out;
	}

	for (i = 0; i < nr; i++) {
		if (git_config_parse_parameter(argv[i], fn, data) < 0) {
			ret = -1;
			goto out;
		}
	}

out:
	free(argv);
	free(envw);
	return ret;
}

static int get_next_char(void)