{
	if (cached || check_index) {
		if (read_file_or_gitlink(ce, buf))
			return error(_("failed to read %s"), name);
	} else if (name) {
		if (S_ISGITLINK(expected_mode)) {
			if (ce)
