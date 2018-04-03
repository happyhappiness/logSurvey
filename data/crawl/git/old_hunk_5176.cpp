		paths[1] = NULL;
	}

	if (!use_index) {
		if (cached)
			die("--cached cannot be used with --no-index.");
