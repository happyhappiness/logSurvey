		return 0;
	}

	if (print_contents == BATCH)
		contents = read_sha1_file(sha1, &type, &size);
	else
		type = sha1_object_info(sha1, &size);

	if (type <= 0) {
		printf("%s missing\n", obj_name);
		fflush(stdout);
		if (print_contents == BATCH)
			free(contents);
		return 0;
	}

	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);
	fflush(stdout);

	if (print_contents == BATCH) {
		write_or_die(1, contents, size);
		printf("\n");
		fflush(stdout);
		free(contents);
	}

	return 0;
}
