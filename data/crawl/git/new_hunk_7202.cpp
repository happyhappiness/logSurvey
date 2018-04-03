			usage(cat_file_usage);

		if (!exp_type) {
			if (batch_check) {
				error("git-cat-file: Can't specify a type (\"%s\") with --batch-check", arg);
				usage(cat_file_usage);
			}

			exp_type = arg;
			continue;
		}

		if (obj_name)
			usage(cat_file_usage);

		// We should have hit one of the earlier if (batch_check) cases before
		// getting here.
		assert(!batch_check);

		obj_name = arg;
		break;
	}

	if (batch_check)
		return batch_objects();

	if (!exp_type || !obj_name)
		usage(cat_file_usage);

