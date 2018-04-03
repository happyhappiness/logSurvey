	}
}

int cmd_check_attr(int argc, const char **argv, const char *prefix)
{
	struct git_attr_check *check;
	int cnt, i, doubledash;

	if (read_cache() < 0) {
		die("invalid cache");
	}

	doubledash = -1;
	for (i = 1; doubledash < 0 && i < argc; i++) {
		if (!strcmp(argv[i], "--"))
			doubledash = i;
	}

	/* If there is no double dash, we handle only one attribute */
	if (doubledash < 0) {
		cnt = 1;
		doubledash = 1;
	} else
		cnt = doubledash - 1;
	doubledash++;

	if (cnt <= 0 || argc < doubledash)
		usage(check_attr_usage);
	check = xcalloc(cnt, sizeof(*check));
	for (i = 0; i < cnt; i++) {
		const char *name;
		struct git_attr *a;
		name = argv[i + 1];
		a = git_attr(name, strlen(name));
		if (!a)
			return error("%s: not a valid attribute name", name);
		check[i].attr = a;
	}

	for (i = doubledash; i < argc; i++)
		check_attr(cnt, check, argv+1, argv[i]);
	maybe_flush_or_die(stdout, "attribute to stdout");
	return 0;
}
