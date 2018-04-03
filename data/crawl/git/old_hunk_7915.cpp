		*arg++ = name;
	}
	*arg = NULL;
	retval = spawn_prog(pgm, spawn_arg);
	remove_tempfile();
	if (retval) {
		fprintf(stderr, "external diff died, stopping at %s.\n", name);