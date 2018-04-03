	if (start_command(&gpg))
		return error("could not run gpg.");

	write_or_die(gpg.in, buffer, size);
	close(gpg.in);
	gpg.close_in = 0;
	len = read_in_full(gpg.out, buffer + size, max - size);

	finish_command(&gpg);

	if (len == max - size)
		return error("could not read the entire signature from gpg.");
