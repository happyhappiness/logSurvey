		opts.new_branch = opts.new_branch_force;

	if (patch_mode && (opts.track > 0 || opts.new_branch
			   || opts.new_branch_log || opts.merge || opts.force
			   || opts.force_detach))
		die ("--patch is incompatible with all other options");

	if (opts.force_detach && (opts.new_branch || opts.new_orphan_branch))
		die("--detach cannot be used with -b/-B/--orphan");
	if (opts.force_detach && 0 < opts.track)
		die("--detach cannot be used with -t");

	/* --track without -b should DWIM */
	if (0 < opts.track && !opts.new_branch) {
		const char *argv0 = argv[0];
