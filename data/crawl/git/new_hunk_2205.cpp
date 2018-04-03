	if (!starts_with(rel, "./") && !starts_with(rel, "../"))
		return NULL;

	if (!is_inside_work_tree())
		die("relative path syntax can't be used outside working tree.");

