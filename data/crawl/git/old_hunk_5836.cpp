
	n = write_in_full(1, content + 11, 41);
	if (n < 41)
		die("git get-tar-commit-id: write error");

	return 0;
}
