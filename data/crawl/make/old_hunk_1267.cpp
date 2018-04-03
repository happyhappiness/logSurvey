	if (!process_begin(hProcess, argv, envp, argv[0], NULL))
		pid = (int) hProcess;
	else
		fatal("expand_function: unable to launch process (e=%d)\n",
		      process_last_err(hProcess));

	/* set up to read data from child */
