{
	int output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (output_fd < 0)
		die("could not create archive file: %s ", output_file);
	if (output_fd != 1) {
		if (dup2(output_fd, 1) < 0)
			die("could not redirect output");
		else
			close(output_fd);
	}
