		else {
			const char *arg = argv[i];

			if (hashstdin) {
				hash_stdin(type, write_object);
				hashstdin = 0;
