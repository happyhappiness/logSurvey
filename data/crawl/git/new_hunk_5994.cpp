	snprintf(tmpfile, sizeof(tmpfile), "%s.temp", filename);
	indexfile = fopen(tmpfile, "a");
	if (!indexfile) {
		ret = error("Unable to open local file %s for pack index",
			    tmpfile);
		goto cleanup_pack;
	}

	slot = get_active_slot();
