	}
	if (!size)
		return -1;

	if (verbose)
		fprintf(stderr, "Serving %s\n", sha1_to_hex(sha1));

	remote = 0;

	if (!has_sha1_file(sha1)) {
		fprintf(stderr, "git-ssh-upload: could not find %s\n",
			sha1_to_hex(sha1));
		remote = -1;
	}

	if (write_in_full(fd_out, &remote, 1) != 1)
		return 0;

	if (remote < 0)
		return 0;

	return write_sha1_to_fd(fd_out, sha1);
}

