
	if (use_scissors && is_scissors_line(line)) {
		int i;
		if (fseek(cmitmsg, 0L, SEEK_SET))
			die_errno("Could not rewind output message file");
		if (ftruncate(fileno(cmitmsg), 0))
			die_errno("Could not truncate output message file at scissors");
		still_looking = 1;

		/*