	if (!*ar)
		die("Unknown archive format '%s'", format);

	if (extra_argc) {
		if (!(*ar)->parse_extra)
			die("'%s' format does not handle %s",
			    (*ar)->name, extra_argv[0]);
		args->extra = (*ar)->parse_extra(extra_argc, extra_argv);
	}
	args->verbose = verbose;
	args->base = base;