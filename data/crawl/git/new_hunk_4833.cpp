	}

	if (diff_filespec_is_binary(one) || diff_filespec_is_binary(two)) {
		data->is_binary = 1;
		data->added = diff_filespec_size(two);
		data->deleted = diff_filespec_size(one);
	}

	else if (complete_rewrite) {