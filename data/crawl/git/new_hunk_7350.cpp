
	display_name(all_matches[0].name);
	if (abbrev)
		show_suffix(all_matches[0].depth, cmit->object.sha1);
	printf("\n");

	if (!last_one)