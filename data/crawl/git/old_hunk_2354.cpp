	if (!strcmp(argv[1], "run-command"))
		exit(run_command(&proc));

	fprintf(stderr, "check usage\n");
	return 1;
}