	}

	/* read the messages */
	if (read_message(stdin, &all_msgs)) {
		fprintf(stderr, "error reading input\n");
		return 1;
	}

	if (all_msgs.len == 0) {
		fprintf(stderr, "nothing to send\n");
		return 1;
	}