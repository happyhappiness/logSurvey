	if (status < 0) {
		if (state->apply_verbosity > verbosity_silent)
			fprintf(stderr,
				"Failed to fall back on three-way merge...\n");
		return status;
	}

