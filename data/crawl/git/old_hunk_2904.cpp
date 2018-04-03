			unsetenv(INDEX_ENVIRONMENT);

		discard_cache();
		read_cache_from(index_lock.filename.buf);
		if (update_main_cache_tree(WRITE_TREE_SILENT) == 0) {
			if (reopen_lock_file(&index_lock) < 0)
				die(_("unable to write index file"));
