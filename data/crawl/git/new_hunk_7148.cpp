	return 0;
}

static const char * const cat_file_usage[] = {
	"git-cat-file [-t|-s|-e|-p|<type>] <sha1>",
	"git-cat-file [--batch|--batch-check] < <list_of_sha1s>",
	NULL
};

int cmd_cat_file(int argc, const char **argv, const char *prefix)
{
	int opt = 0, batch = 0;
	const char *exp_type = NULL, *obj_name = NULL;

	const struct option options[] = {
		OPT_GROUP("<type> can be one of: blob, tree, commit, tag"),
		OPT_SET_INT('t', NULL, &opt, "show object type", 't'),
		OPT_SET_INT('s', NULL, &opt, "show object size", 's'),
		OPT_SET_INT('e', NULL, &opt,
			    "exit with zero when there's no error", 'e'),
		OPT_SET_INT('p', NULL, &opt, "pretty-print object's content", 'p'),
		OPT_SET_INT(0, "batch", &batch,
			    "show info and content of objects feeded on stdin", BATCH),
		OPT_SET_INT(0, "batch-check", &batch,
			    "show info about objects feeded on stdin",
			    BATCH_CHECK),
		OPT_END()
	};

	git_config(git_default_config);

	if (argc != 3 && argc != 2)
		usage_with_options(cat_file_usage, options);

	argc = parse_options(argc, argv, options, cat_file_usage, 0);

	if (opt) {
		if (argc == 1)
			obj_name = argv[0];
		else
			usage_with_options(cat_file_usage, options);
	}
	if (!opt && !batch) {
		if (argc == 2) {
			exp_type = argv[0];
			obj_name = argv[1];
		} else
			usage_with_options(cat_file_usage, options);
	}
	if (batch && (opt || argc)) {
		usage_with_options(cat_file_usage, options);
	}

	if (batch)
		return batch_objects(batch);

	return cat_one_file(opt, exp_type, obj_name);
}