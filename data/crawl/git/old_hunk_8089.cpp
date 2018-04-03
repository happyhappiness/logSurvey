		write_or_die(fd, tag_template, strlen(tag_template));
		close(fd);

		launch_editor(path, &buffer, &size);

		unlink(path);
		free(path);
	}
	else {
		buffer = message;
		size = strlen(message);
	}

	size = stripspace(buffer, size, 1);

	if (!message && !size)
		die("no tag message?");

	/* insert the header and add the '\n' if needed: */
	max_size = header_len + size + (sign ? MAX_SIGNATURE_LENGTH : 0) + 1;
	buffer = xrealloc(buffer, max_size);
	if (size)
		buffer[size++] = '\n';
	memmove(buffer + header_len, buffer, size);
	memcpy(buffer, header_buf, header_len);
	size += header_len;

	if (sign) {
		ssize_t r = do_sign(buffer, size, max_size);
		if (r < 0)
			die("unable to sign the tag");
		size = r;
	}

	if (write_sha1_file(buffer, size, tag_type, result) < 0)
		die("unable to write tag file");
	free(buffer);
}

int cmd_tag(int argc, const char **argv, const char *prefix)
{
	unsigned char object[20], prev[20];
	int annotate = 0, sign = 0, force = 0, lines = 0;
	char *message = NULL;
	char ref[PATH_MAX];
	const char *object_ref, *tag;
	int i;
	struct ref_lock *lock;

	git_config(git_tag_config);

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
