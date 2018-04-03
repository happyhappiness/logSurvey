	if (argc > 2)
		die("too many options");

	ret = write_tree(sha1, missing_ok, prefix);
	printf("%s\n", sha1_to_hex(sha1));

	return ret;
}
