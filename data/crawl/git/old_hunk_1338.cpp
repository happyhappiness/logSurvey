		strbuf_release(&idx_file);
	}

	if (shallow_file) {
		argv[ac++] = "--shallow-file";
		argv[ac++] = shallow_file;
	}
	argv[ac++] = "rev-list";
	argv[ac++] = "--objects";
	argv[ac++] = "--stdin";
	argv[ac++] = "--not";
	argv[ac++] = "--all";
	if (quiet)
		argv[ac++] = "--quiet";
	argv[ac] = NULL;

	rev_list.argv = argv;
	rev_list.git_cmd = 1;
	rev_list.in = -1;
	rev_list.no_stdout = 1;
	rev_list.no_stderr = quiet;
	if (start_command(&rev_list))
		return error(_("Could not run 'git rev-list'"));

