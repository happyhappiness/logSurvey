		*arg++ = name;
	}
	*arg = NULL;
	fflush(NULL);
	retval = run_command_v_opt(spawn_arg, 0);
	remove_tempfile();
	if (retval) {
		fprintf(stderr, "external diff died, stopping at %s.\n", name);