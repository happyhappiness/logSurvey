			warning(_("Failed to update main cache tree"));

		commit_style = COMMIT_NORMAL;
		return index_lock.filename.buf;
	}

	/*
