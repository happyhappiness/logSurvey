
	if (mi->use_scissors && is_scissors_line(line)) {
		int i;
		if (fseek(mi->cmitmsg, 0L, SEEK_SET))
			die_errno("Could not rewind output message file");
		if (ftruncate(fileno(mi->cmitmsg), 0))
			die_errno("Could not truncate output message file at scissors");
		mi->header_stage = 1;

