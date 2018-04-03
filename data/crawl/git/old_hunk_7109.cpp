	else
		type = sha1_object_info(sha1, &size);

	if (type <= 0)
		return 1;

	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);
	fflush(stdout);
