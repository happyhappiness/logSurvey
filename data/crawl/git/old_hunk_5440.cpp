	}
	if (!committer)
		die("Expected committer but didn't get one");
	parse_data(&msg);
	read_next_command();
	parse_from(b);
	merge_list = parse_merge(&merge_count);