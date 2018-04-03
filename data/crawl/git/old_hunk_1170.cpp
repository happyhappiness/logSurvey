		} else
			usage_with_options(cat_file_usage, options);
	}
	if (batch.enabled && (opt || argc)) {
		usage_with_options(cat_file_usage, options);
	}

	if ((batch.follow_symlinks || batch.all_objects) && !batch.enabled) {
