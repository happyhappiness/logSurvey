	retval = -1;
	while ((sha1 = get_rev())) {
		packet_write(fd[1], "have %s\n", sha1_to_hex(sha1));
		if (verbose)
			fprintf(stderr, "have %s\n", sha1_to_hex(sha1));
		in_vain++;
		if (!(31 & ++count)) {
