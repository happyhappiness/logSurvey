	 * but handles the potential overflow case specially (and we
	 * assume at least 32-bit integers)
	 */
	options->needed_rename_limit = 0;
	if (rename_limit <= 0 || rename_limit > 32767)
		rename_limit = 32767;
	if ((num_create > rename_limit && num_src > rename_limit) ||
	    (num_create * num_src > rename_limit * rename_limit)) {
		options->needed_rename_limit =
			num_src > num_create ? num_src : num_create;
		goto cleanup;
	}

