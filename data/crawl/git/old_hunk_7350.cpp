
	display_name(all_matches[0].name);
	if (abbrev)
		printf("-%d-g%s", all_matches[0].depth,
		       find_unique_abbrev(cmit->object.sha1, abbrev));
	printf("\n");

	if (!last_one)