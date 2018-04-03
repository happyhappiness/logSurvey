	if (!starts_with(rel, "./") && !starts_with(rel, "../"))
		return NULL;

	if (!startup_info)
		die("BUG: startup_info struct is not initialized.");

	if (!is_inside_work_tree())
		die("relative path syntax can't be used outside working tree.");

