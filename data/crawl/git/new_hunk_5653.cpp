		return cmd_name_rev(i + argc, args, prefix);
	}

	for_each_ref(get_name, NULL);
	if (!found_names)
		die("No names found, cannot describe anything.");

	if (argc == 0) {
		describe("HEAD", 1);
	} else {