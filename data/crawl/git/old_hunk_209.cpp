	struct argv_array apply_opts = ARGV_ARRAY_INIT;
	struct apply_state apply_state;
	int res, opts_left;
	static struct lock_file lock_file;
	int force_apply = 0;
	int options = 0;

	if (init_apply_state(&apply_state, NULL, &lock_file))
		die("BUG: init_apply_state() failed");

	argv_array_push(&apply_opts, "apply");
