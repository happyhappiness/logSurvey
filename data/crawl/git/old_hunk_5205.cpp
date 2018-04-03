			die("program error");
	}

	if (parse_options(argc, argv, NULL, options, usage_str, 0) != 1)
		usage_with_options(usage_str, options);

	commit_name = argv[0];
	if (get_sha1(commit_name, sha1))
		die ("Cannot find '%s'", commit_name);
	commit = lookup_commit_reference(sha1);
	if (!commit)
		exit(1);
}

struct commit_message {
