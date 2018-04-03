	int argc;
	int err;

	argv = xmalloc((refspec_nr + 11) * sizeof(char *));
	argv[0] = "http-push";
	argc = 1;
