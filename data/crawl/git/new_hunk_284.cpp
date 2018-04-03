	if (!tempfile->active)
		die("BUG: rename_tempfile called for inactive object");

	if (close_tempfile_gently(tempfile)) {
		delete_tempfile(tempfile);
		return -1;
	}

	if (rename(tempfile->filename.buf, path)) {
		int save_errno = errno;
