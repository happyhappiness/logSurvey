	if (pack_to_stdout != !base_name)
		usage(pack_usage);

	if (!pack_to_stdout && thin)
		die("--thin cannot be used to build an indexable pack.");
