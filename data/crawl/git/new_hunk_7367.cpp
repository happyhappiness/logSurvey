	 */
	if (rename_limit <= 0 || rename_limit > 32767)
		rename_limit = 32767;
	if ((num_create > rename_limit && num_src > rename_limit) ||
	    (num_create * num_src > rename_limit * rename_limit)) {
		warning("too many files, skipping inexact rename detection");
		goto cleanup;
	}

	mx = xmalloc(sizeof(*mx) * num_create * num_src);
	for (dst_cnt = i = 0; i < rename_dst_nr; i++) {