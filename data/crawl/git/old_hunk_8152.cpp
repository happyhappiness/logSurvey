		cache_tree_invalidate_path(active_cache_tree, patch->old_name);
	}
	if (!cached) {
		if (!unlink(patch->old_name) && rmdir_empty) {
			char *name = xstrdup(patch->old_name);
			char *end = strrchr(name, '/');
			while (end) {
