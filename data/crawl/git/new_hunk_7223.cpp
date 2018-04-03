	opts.rename_limit = merge_rename_limit >= 0 ? merge_rename_limit :
			    diff_rename_limit >= 0 ? diff_rename_limit :
			    500;
	opts.warn_on_too_large_rename = 1;
	opts.output_format = DIFF_FORMAT_NO_OUTPUT;
	if (diff_setup_done(&opts) < 0)
		die("diff setup failed");
