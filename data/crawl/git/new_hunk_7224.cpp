		rename_limit = 32767;
	if ((num_create > rename_limit && num_src > rename_limit) ||
	    (num_create * num_src > rename_limit * rename_limit)) {
		if (options->warn_on_too_large_rename)
			warning("too many files, skipping inexact rename detection");
		goto cleanup;
	}
