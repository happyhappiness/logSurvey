			hashclr(sha1);
		if (check_local_mod(sha1, index_only))
			exit(1);
	}

	/*
	 * First remove the names from the index: we won't commit
	 * the index unless all of them succeed.
	 */
	for (i = 0; i < list.nr; i++) {
		const char *path = list.name[i];
		if (!quiet)
			printf("rm '%s'\n", path);

