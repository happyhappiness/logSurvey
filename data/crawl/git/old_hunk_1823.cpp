{
	if (cached || check_index) {
		if (read_file_or_gitlink(ce, buf))
			return error(_("read of %s failed"), name);
	} else if (name) {
		if (S_ISGITLINK(expected_mode)) {
			if (ce)
