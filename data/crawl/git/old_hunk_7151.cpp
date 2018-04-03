			}
			else if (!strcmp(argv[i], "--help"))
				usage(hash_object_usage);
			else if (!strcmp(argv[i], "--stdin")) {
				if (hashstdin)
					die("Multiple --stdin arguments are not supported");
				hashstdin = 1;
