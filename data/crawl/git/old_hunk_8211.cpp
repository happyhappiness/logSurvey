				die("argument to option -u too long");
			continue;
		}
		if (!strcmp(arg, "-l")) {
			return list_tags(argv[i + 1], lines);
		}
		if (!strcmp(arg, "-d")) {
			return do_tag_names(argv + i + 1, delete_tag);
		}
		if (!strcmp(arg, "-v")) {
			return do_tag_names(argv + i + 1, verify_tag);
		}
		usage(builtin_tag_usage);
	}

