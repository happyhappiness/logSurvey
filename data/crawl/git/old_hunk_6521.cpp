	}

	ret = start_command(&hook);
	if (ret) {
		warning("Could not spawn %s", argv[0]);
		return ret;