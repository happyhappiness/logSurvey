
	trace_argv_printf(argv, "trace: exec:");

	/* execvp() can only ever return if it fails */
	execvp(cmd.buf, (char **)argv);

	trace_printf("trace: exec failed: %s\n", strerror(errno));

	argv[0] = tmp;
