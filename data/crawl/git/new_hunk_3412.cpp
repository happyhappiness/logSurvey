	if (keep_unreachable && unpack_unreachable)
		die("--keep-unreachable and --unpack-unreachable are incompatible.");

	if (!use_internal_rev_list || !pack_to_stdout || is_repository_shallow())
		use_bitmap_index = 0;

	if (progress && all_progress_implied)
		progress = 2;
