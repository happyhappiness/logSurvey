			else if (!strcmp(argv[i], "--help"))
				usage(hash_object_usage);
			else if (!strcmp(argv[i], "--stdin")) {
				hash_stdin(type, write_object);
			}
			else
				usage(hash_object_usage);
		}
		else {
			const char *arg = argv[i];
			if (0 <= prefix_length)
				arg = prefix_filename(prefix, prefix_length,
						      arg);
			hash_object(arg, type_from_string(type), write_object);
			no_more_flags = 1;
		}
	}
	return 0;
}
