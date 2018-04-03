	}

	/* read the messages */
	if (!read_message(stdin, &all_msgs)) {
		fprintf(stderr, "nothing to send\n");
		return 1;
	}