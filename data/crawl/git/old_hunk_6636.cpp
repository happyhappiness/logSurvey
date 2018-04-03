	}
	if (sign)
		annotate = 1;

	if (list)
		return list_tags(argv[0], lines);
	if (delete)
		return for_each_tag_name(argv, delete_tag);
	if (verify)
