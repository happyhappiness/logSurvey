		die (_("--patch is incompatible with all other options"));

	if (opts.force_detach && (opts.new_branch || opts.new_orphan_branch))
		die(_("--detach cannot be used with -b/-B/--orphan"));
	if (opts.force_detach && 0 < opts.track)
		die(_("--detach cannot be used with -t"));

	/* --track without -b should DWIM */
	if (0 < opts.track && !opts.new_branch) {
