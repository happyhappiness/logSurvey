		prefix = setup_git_directory();
	if (p->option & USE_PAGER)
		setup_pager();
	if (p->option & NEED_WORK_TREE)
		setup_work_tree();

	trace_argv_printf(argv, argc, "trace: built-in: git");

	status = p->fn(argc, argv, prefix);
