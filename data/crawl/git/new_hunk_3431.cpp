		if (argc != 2)
			usage_msg_opt("bad number of arguments",
				      git_replace_usage, options);
		if (format)
			usage_msg_opt("--format cannot be used when not listing",
				      git_replace_usage, options);
		return replace_object(argv[0], argv[1], force);
	}

