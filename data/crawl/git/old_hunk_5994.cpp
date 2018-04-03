	snprintf(tmpfile, sizeof(tmpfile), "%s.temp", filename);
	indexfile = fopen(tmpfile, "a");
	if (!indexfile) {
		free(url);
		return error("Unable to open local file %s for pack index",
			     tmpfile);
	}

	slot = get_active_slot();
