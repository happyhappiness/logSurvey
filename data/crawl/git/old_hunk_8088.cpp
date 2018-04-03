	if (start_command(&gpg))
		return error("could not run gpg.");

	if (write_in_full(gpg.in, buffer, size) != size) {
		close(gpg.in);
		finish_command(&gpg);
		return error("gpg did not accept the tag data");
	}
	close(gpg.in);
	gpg.close_in = 0;
	len = read_in_full(gpg.out, buffer + size, max - size);

	if (finish_command(&gpg) || !len || len < 0)
		return error("gpg failed to sign the tag");

	if (len == max - size)
		return error("could not read the entire signature from gpg.");

	return size + len;
}

static const char tag_template[] =
