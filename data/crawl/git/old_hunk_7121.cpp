	if (!from_stdin) {
		close(input_fd);
	} else {
		err = close(output_fd);
		if (err)
			die("error while closing pack file: %s", strerror(errno));
