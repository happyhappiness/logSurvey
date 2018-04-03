			usage(cat_file_usage);

		if (!exp_type) {
			exp_type = arg;
			continue;
		}

		if (obj_name)
			usage(cat_file_usage);

		obj_name = arg;
		break;
	}

	if (!exp_type || !obj_name)
		usage(cat_file_usage);

