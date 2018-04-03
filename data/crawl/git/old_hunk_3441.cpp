				   args.verbose ? CONNECT_VERBOSE : 0);
	}

	get_remote_heads(fd[0], NULL, 0, &ref, 0, NULL, NULL);

	ref = fetch_pack(&args, fd, conn, ref, dest,
			 sought, nr_sought, NULL, pack_lockfile_ptr);
	if (pack_lockfile) {
		printf("lock %s\n", pack_lockfile);
		fflush(stdout);
