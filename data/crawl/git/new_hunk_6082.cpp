		 "%s.temp", filename);

	snprintf(prevfile, sizeof(prevfile), "%s.prev", request->filename);
	unlink_or_warn(prevfile);
	rename(request->tmpfile, prevfile);
	unlink_or_warn(request->tmpfile);

	if (request->local_fileno != -1)
		error("fd leakage in start: %d", request->local_fileno);
