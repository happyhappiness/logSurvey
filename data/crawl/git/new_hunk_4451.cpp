		close(bundle_fd);
		if (verify_bundle(&header, 1))
			return 1;
		fprintf(stderr, _("%s is okay\n"), bundle_file);
		return 0;
	}
	if (!strcmp(cmd, "list-heads")) {
