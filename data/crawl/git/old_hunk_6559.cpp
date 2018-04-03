			add_pack_file(*(argv + i++));

	if (local_packs == NULL)
		die("Zero packs found!\n");

	load_all_objects();
