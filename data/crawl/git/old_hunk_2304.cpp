		the_index.split_index = NULL;
		the_index.cache_changed |= SOMETHING_CHANGED;
	}
	if (untracked_cache > UC_DISABLE) {
		if (untracked_cache < UC_FORCE) {
			setup_work_tree();
			if (!test_if_untracked_cache_is_supported())
				return 1;
			if (untracked_cache == UC_TEST)
				return 0;
		}
		add_untracked_cache(&the_index);
		report(_("Untracked cache enabled for '%s'"), get_git_work_tree());
	} else if (untracked_cache == UC_DISABLE) {
		remove_untracked_cache(&the_index);
		report(_("Untracked cache disabled"));
	}

	if (active_cache_changed) {
