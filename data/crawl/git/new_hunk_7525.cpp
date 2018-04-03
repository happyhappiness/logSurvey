			fprintf(stderr, "Server supports side-band\n");
		use_sideband = 1;
	}
	if (everything_local(&ref, nr_match, match)) {
		packet_flush(fd[1]);
		goto all_done;
