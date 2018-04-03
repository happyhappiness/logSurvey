	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (!strcmp(arg, "--decorate")) {
			load_ref_decorations();
			rev->show_decorations = 1;
		} else if (!strcmp(arg, "--source")) {
			rev->show_source = 1;
		} else
			die("unrecognized argument: %s", arg);
	}
}

/*
