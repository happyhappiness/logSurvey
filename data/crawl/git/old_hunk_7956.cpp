	rev.diffopt.output_format = DIFF_FORMAT_CALLBACK;
	rev.diffopt.format_callback = update_callback;
	rev.diffopt.format_callback_data = &verbose;
	if (read_cache() < 0)
		die("index file corrupt");
	run_diff_files(&rev, 0);
}

