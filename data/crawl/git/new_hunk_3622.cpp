	if (!work_tree)
		goto out;

	if (read_cache() < 0)
		die("index file corrupt");

	argv_array_push(&argv, "fetch");
	for (i = 0; i < options->argc; i++)