
		buf = xstrdup(v);
		argc = split_cmdline(buf, &argv);
		argv = xrealloc(argv, sizeof(*argv) * (argc + 2));
		memmove(argv + 1, argv, sizeof(*argv) * (argc + 1));
		argc++;
