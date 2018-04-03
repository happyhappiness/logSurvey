	return 0;
}

static const char cat_file_usage[] = "git-cat-file [ [-t|-s|-e|-p|<type>] <sha1> | [--batch|--batch-check] < <list_of_sha1s> ]";

int cmd_cat_file(int argc, const char **argv, const char *prefix)
{
	int i, opt = 0, batch = 0, batch_check = 0;
	const char *exp_type = NULL, *obj_name = NULL;

	git_config(git_default_config);

	for (i = 1; i < argc; ++i) {
		const char *arg = argv[i];
		int is_batch = 0, is_batch_check = 0;

		is_batch = !strcmp(arg, "--batch");
		if (!is_batch)
			is_batch_check = !strcmp(arg, "--batch-check");

		if (is_batch || is_batch_check) {
			if (opt) {
				error("git-cat-file: Can't use %s with -%c", arg, opt);
				usage(cat_file_usage);
			} else if (exp_type) {
				error("git-cat-file: Can't use %s when a type (\"%s\") is specified", arg, exp_type);
				usage(cat_file_usage);
			} else if (obj_name) {
				error("git-cat-file: Can't use %s when an object (\"%s\") is specified", arg, obj_name);
				usage(cat_file_usage);
			}

			if ((is_batch && batch_check) || (is_batch_check && batch)) {
				error("git-cat-file: Can't use %s with %s", arg, is_batch ? "--batch-check" : "--batch");
				usage(cat_file_usage);
			}

			if (is_batch)
				batch = 1;
			else
				batch_check = 1;

			continue;
		}

		if (!strcmp(arg, "-t") || !strcmp(arg, "-s") || !strcmp(arg, "-e") || !strcmp(arg, "-p")) {
			if (batch || batch_check) {
				error("git-cat-file: Can't use %s with %s", arg, batch ? "--batch" : "--batch-check");
				usage(cat_file_usage);
			}

			exp_type = arg;
			opt = exp_type[1];
			continue;
		}

		if (arg[0] == '-')
			usage(cat_file_usage);

		if (!exp_type) {
			if (batch || batch_check) {
				error("git-cat-file: Can't specify a type (\"%s\") with %s", arg, batch ? "--batch" : "--batch-check");
				usage(cat_file_usage);
			}

			exp_type = arg;
			continue;
		}

		if (obj_name)
			usage(cat_file_usage);

		// We should have hit one of the earlier if (batch || batch_check) cases before
		// getting here.
		assert(!batch);
		assert(!batch_check);

		obj_name = arg;
		break;
	}

	if (batch || batch_check)
		return batch_objects(batch);

	if (!exp_type || !obj_name)
		usage(cat_file_usage);

	return cat_one_file(opt, exp_type, obj_name);
}