			}
			else if (!strcmp(argv[i], "--help"))
				usage(hash_object_usage);
			else if (!strcmp(argv[i], "--stdin-paths")) {
				if (hashstdin) {
					error("Can't use --stdin-paths with --stdin");
					usage(hash_object_usage);
				}
				stdin_paths = 1;

			}
			else if (!strcmp(argv[i], "--stdin")) {
				if (stdin_paths) {
					error("Can't use %s with --stdin-paths", argv[i]);
					usage(hash_object_usage);
				}
				if (hashstdin)
					die("Multiple --stdin arguments are not supported");
				hashstdin = 1;
