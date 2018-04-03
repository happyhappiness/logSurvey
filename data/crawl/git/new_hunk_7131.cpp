	rollback_lock_file(lock_file);
}

static int builtin_diff_files(struct rev_info *revs, int argc, const char **argv)
{
	int result;
	unsigned int options = 0;

	while (1 < argc && argv[1][0] == '-') {
		if (!strcmp(argv[1], "--base"))
			revs->max_count = 1;
		else if (!strcmp(argv[1], "--ours"))
			revs->max_count = 2;
		else if (!strcmp(argv[1], "--theirs"))
			revs->max_count = 3;
		else if (!strcmp(argv[1], "-q"))
			options |= DIFF_SILENT_ON_REMOVED;
		else
			return error("invalid option: %s", argv[1]);
		argv++; argc--;
	}

	if (revs->max_count == -1 &&
	    (revs->diffopt.output_format & DIFF_FORMAT_PATCH))
		revs->combine_merges = revs->dense_combined_merges = 1;

	if (read_cache() < 0) {
		perror("read_cache");
		return -1;
	}
	result = run_diff_files(revs, options);
	return diff_result_code(&revs->diffopt, result);
}

int cmd_diff(int argc, const char **argv, const char *prefix)
{
	int i;
