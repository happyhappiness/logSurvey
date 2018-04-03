
	display_name(all_matches[0].name);
	if (abbrev)
		show_suffix(all_matches[0].depth, cmit->object.oid.hash);
	if (dirty)
		printf("%s", dirty);
	printf("\n");
