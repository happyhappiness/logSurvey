	argv[arg++] = NULL;

	memset(&pack_objects, 0, sizeof(pack_objects));
	pack_objects.in = rev_list.out;	/* start_command closes it */
	pack_objects.out = -1;
	pack_objects.err = -1;
	pack_objects.git_cmd = 1;
	pack_objects.argv = argv;

	if (start_command(&pack_objects)) {
		/* daemon sets things up to ignore TERM */
		kill(rev_list.pid, SIGKILL);
		die("git-upload-pack: unable to fork git-pack-objects");
	}

