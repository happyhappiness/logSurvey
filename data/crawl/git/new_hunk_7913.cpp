		*av++ = hdr_arg;
	*av++ = NULL;

	cmd.in = fd[0];
	cmd.git_cmd = 1;
	if (start_command(&cmd))
		die("fetch-pack: unable to fork off %s", argv[0]);
	close(fd[1]);
	if (do_keep && pack_lockfile)
		*pack_lockfile = index_pack_lockfile(cmd.out);

	if (finish_command(&cmd))
		die("%s failed", argv[0]);
	return 0;
}

static struct ref *do_fetch_pack(int fd[2],