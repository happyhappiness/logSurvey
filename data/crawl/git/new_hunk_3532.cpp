		return 0;
	}

	type = sha1_object_info(sha1, &size);
	if (type <= 0) {
		printf("%s missing\n", obj_name);
		fflush(stdout);
		return 0;
	}

	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);
	fflush(stdout);

	if (print_contents == BATCH) {
		print_object_or_die(1, sha1, type, size);
		write_or_die(1, "\n", 1);
	}
	return 0;
}
