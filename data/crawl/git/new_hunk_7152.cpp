		else {
			const char *arg = argv[i];

			if (stdin_paths) {
				error("Can't specify files (such as \"%s\") with --stdin-paths", arg);
				usage(hash_object_usage);
			}

			if (hashstdin) {
				hash_stdin(type, write_object);
				hashstdin = 0;
