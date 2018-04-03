			warning(_("Failed to update main cache tree"));

		commit_style = COMMIT_NORMAL;
		return get_lock_file_path(&index_lock);
	}

	/*
