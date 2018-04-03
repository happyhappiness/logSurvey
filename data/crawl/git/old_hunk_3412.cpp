	if (keep_unreachable && unpack_unreachable)
		die("--keep-unreachable and --unpack-unreachable are incompatible.");

	if (progress && all_progress_implied)
		progress = 2;
