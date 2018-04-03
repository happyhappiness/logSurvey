
	if (use_scissors && is_scissors_line(line)) {
		int i;
		rewind(cmitmsg);
		ftruncate(fileno(cmitmsg), 0);
		still_looking = 1;

		/*