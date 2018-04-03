	return !!rv;
}

static const char *extract_remote_arg(int *ac, const char **av)
{
	int ix, iy, cnt = *ac;
	int no_more_options = 0;
	const char *remote = NULL;

	for (ix = iy = 1; ix < cnt; ix++) {
		const char *arg = av[ix];
		if (!strcmp(arg, "--"))
			no_more_options = 1;
		if (!no_more_options) {
			if (!prefixcmp(arg, "--remote=")) {
				if (remote)
					die("Multiple --remote specified");
				remote = arg + 9;
				continue;
			} else if (!strcmp(arg, "--remote")) {
				if (remote)
					die("Multiple --remote specified");
				if (++ix >= cnt)
					die("option --remote requires a value");
				remote = av[ix];
				continue;
			}
			if (arg[0] != '-')
				no_more_options = 1;
		}
		if (ix != iy)
			av[iy] = arg;
		iy++;
	}
	if (remote) {
		av[--cnt] = NULL;
		*ac = cnt;
	}
	return remote;
}

int cmd_archive(int argc, const char **argv, const char *prefix)
{
	const char *remote = NULL;

	remote = extract_remote_arg(&argc, argv);
	if (remote)
		return run_remote_archiver(remote, argc, argv);

	setvbuf(stderr, NULL, _IOLBF, BUFSIZ);
