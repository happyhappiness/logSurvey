			return 0;
		if (!state->force) {
			if (!state->quiet)
				fprintf(stderr, "%s already exists, no checkout\n", path);
			return -1;
		}
