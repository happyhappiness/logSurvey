	get_remote_heads(fd[0], &ref, 0, NULL);

	ref = fetch_pack(&args, fd, conn, ref, dest,
			 sought, nr_sought, pack_lockfile_ptr);
	if (pack_lockfile) {
		printf("lock %s\n", pack_lockfile);
		fflush(stdout);
