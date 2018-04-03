	po.out = fd;
	po.git_cmd = 1;
	if (start_command(&po))
		die("git pack-objects failed (%s)", strerror(errno));

	/*
	 * We feed the pack-objects we just spawned with revision
