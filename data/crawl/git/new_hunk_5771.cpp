	 * OK to return. Otherwise, we just pass along the status code.
	 */
	status = run_command_v_opt(argv, 0);
	if (status >= 0 || errno != ENOENT)
		exit(status);

	argv[0] = tmp;

