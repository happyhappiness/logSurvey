	unsigned char *c;

	if (argc < 2 || argc > 3) {
		fprintf(stderr, "usage: %s <seed_string> [<size>]\n", argv[0]);
		return 1;
	}
