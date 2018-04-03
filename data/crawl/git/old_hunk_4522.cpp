static void die_if_unmerged_cache(int reset_type)
{
	if (is_merge() || read_cache() < 0 || unmerged_cache())
		die("Cannot do a %s reset in the middle of a merge.",
		    reset_type_names[reset_type]);

}

