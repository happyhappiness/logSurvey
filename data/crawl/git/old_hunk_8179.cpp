		prefix = setup_git_directory();
	if (p->option & USE_PAGER)
		setup_pager();
	if ((p->option & NEED_WORK_TREE) &&
	    (!is_inside_work_tree() || is_inside_git_dir()))
		die("%s must be run in a work tree", p->cmd);
	trace_argv_printf(argv, argc, "trace: built-in: git");

	status = p->fn(argc, argv, prefix);
