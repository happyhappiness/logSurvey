	if (!ok_to_add)
		return -1;
	if (!verify_path(ce->name))
		return -1;

	if (!skip_df_check &&
	    check_file_directory_conflict(istate, ce, pos, ok_to_replace)) {