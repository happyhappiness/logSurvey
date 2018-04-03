	if (start_command(&pack_objects))
		die("git upload-pack: unable to fork git-pack-objects");

	/* pass on revisions we (don't) want */
	if (!shallow_nr) {
		FILE *pipe_fd = xfdopen(pack_objects.in, "w");
		if (!create_full_pack) {
			int i;