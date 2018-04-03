
	fd = hold_lock_file_for_update(&false_lock,
				       git_path("next-index-%d", getpid()), 1);

	create_base_index();
	add_remove_files(&partial);
	refresh_cache(REFRESH_QUIET);
