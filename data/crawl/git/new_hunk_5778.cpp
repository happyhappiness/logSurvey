		argv[argc++] = *refspec++;
	argv[argc] = NULL;
	err = run_command_v_opt(argv, RUN_GIT_CMD);
	if (err < 0 && errno == ENOENT)
		error("unable to exec %s", argv[0]);
	return !!err;
}
