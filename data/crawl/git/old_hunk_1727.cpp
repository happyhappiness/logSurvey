	 */
	const char **argv = (const char **)av;

	argv[0] = git_extract_argv0_path(argv[0]);

	return cmd_main(argc, argv);
