
	hashmap_init(&names, commit_name_cmp, NULL, 0);
	for_each_rawref(get_name, NULL);
	if (!hashmap_get_size(&names) && !always)
		die(_("No names found, cannot describe anything."));

	if (argc == 0) {
