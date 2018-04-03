	const char *argv[10];
	int arg = 0;

	argv[arg++] = "pack-objects";
	if (!shallow_nr) {
		argv[arg++] = "--revs";
		if (create_full_pack)
			argv[arg++] = "--all";
