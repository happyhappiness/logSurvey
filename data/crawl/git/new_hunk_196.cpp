	switch (ce_mode_s_ifmt) {
	case S_IFREG:
	case S_IFLNK:
		/*
		 * We do not send the blob in case of a retry, so do not
		 * bother reading it at all.
		 */
		if (ce_mode_s_ifmt == S_IFREG && dco && dco->state == CE_RETRY) {
			new = NULL;
			size = 0;
		} else {
			new = read_blob_entry(ce, &size);
			if (!new)
				return error("unable to read sha1 file of %s (%s)",
					     path, oid_to_hex(&ce->oid));
		}

		if (ce_mode_s_ifmt == S_IFLNK && has_symlinks && !to_tempfile) {
			ret = symlink(new, path);
